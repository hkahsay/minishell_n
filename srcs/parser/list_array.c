#include "../../headers/minishell.h"

int ft_cmd_size(t_cmd *node)
{
    t_wr_node *args = node->cmd_wnode;
    int size = 0;
    while (args != NULL) {
        if (args->file != NULL)
            size++;
        args= args->next;
    }
    return size;
}


void ft_envnode_sort(t_envnode *mini_env)
{
    int sorted = 0; // flag to indicate if list is sorted
    t_envnode *current;
    // t_envnode *next;
    t_envnode  temp;

    while (!sorted)
    {
        sorted = 1; // assume the list is sorted initially
        current = mini_env;

        while (current && current->next)
        {
            if (ft_strcmp(current->key, current->next->key) > 0)
            {
                // swap the key of the current and next nodes
                // temp = ft_strdup(current->key);
                // free(current->key);
                // current->key = ft_strdup(current->next->key);
                // free(current->next->key);
                // current->next->key = ft_strdup(temp);
                // free(temp);
                // printf("key: %s\n", current->key);
                // printf("value: %s\n", current->value);
                temp.key = ft_strdup(current->key);
                temp.value = ft_strdup(current->value);
                free(current->key);
                free(current->value);
                current->key = ft_strdup(current->next->key);
                current->value = ft_strdup(current->next->value);
                free(current->next->key);
                free(current->next->value);
                current->next->key = ft_strdup(temp.key);
                current->next->value = ft_strdup(temp.value);

                sorted = 0; // the list is not sorted yet
            }
            current = current->next;
        }
    }

    printf("DECLARE -X %s = %s\n", current->key, current->value);
}

// t_envnode	*sort_envnode(t_envnode *lst, int (*cmp)(char *, char *))
// {
// 	char	*swap;
// 	t_envnode	*tmp;

// 	tmp = lst;
// 	while(lst->next != NULL)
// 	{
//         // printf("lst->key %s\n", lst->key);
//         // printf("lst->key->next %s\n", lst->next->key);
//         // printf("new : %ld\n", lst->key - lst->next->key);
// 		if (((*cmp)(lst->key, lst->next->key)) == 0)
// 		{
// 			swap = lst->key;
// 			lst->key = lst->next->key;
//             printf("new : %ld\n", lst->key - lst->next->key);
// 		    lst->next->key = swap;
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }


char    **create_array(t_cmd **cmd_head)
{
    int size;
    char    **array_cmd;
    int     i;
    // node = cmd_head;
    t_cmd *cmd_temp = *cmd_head;
	char	*trimmed;

    size = ft_cmd_size(cmd_temp);
    printf(OR "size %d\n" RS, size);
 
    array_cmd = malloc(sizeof(char *) * (size + 1));
    printf(OR "&array_cmd %p\n" RS, array_cmd);
    if (!array_cmd)
        return (0);
	cmd_temp = *cmd_head;
	i = 0;
    while (cmd_temp && i < size) // && !cmd_temp->cmd_wnode && 
    {
		if (cmd_temp->cmd_wnode->type == TOK_SPACE)
			cmd_temp->cmd_wnode = cmd_temp->cmd_wnode->next;
        if (cmd_temp->cmd_wnode->type == TOK_D_QUOTE)
		{
			trimmed = ft_strtrim(cmd_temp->cmd_wnode->file, "\"");
			free(cmd_temp->cmd_wnode->file);
			cmd_temp->cmd_wnode->file = ft_strdup(trimmed);
			printf(YELLOW "cmd_temp->cmd_wnode->file %s\n" RS, cmd_temp->cmd_wnode->file);
		}
        if (cmd_temp->cmd_wnode != NULL)

            array_cmd[i] = cmd_temp->cmd_wnode->file;

        printf("array_cmd[%d] %s\n", i, array_cmd[i]);
        i++;
        cmd_temp->cmd_wnode = cmd_temp->cmd_wnode->next;
    }
    array_cmd[i] = NULL;
    print_array(array_cmd);
    //    printf("from create array %s\n", array_cmd[i++]);
    return(array_cmd);

}