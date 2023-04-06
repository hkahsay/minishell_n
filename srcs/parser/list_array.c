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

void merge_sort_env(t_envnode **head_ref)
{
    t_envnode *head = *head_ref;
    t_envnode *a;
    t_envnode *b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    // Split the list into two sublists
    front_back_split(head, &a, &b);
 
    // Recursively sort the sublists
    merge_sort_env(&a);
    merge_sort_env(&b);
 
    // Merge the sorted sublists
    *head_ref = sorted_merge_env(a, b);
}
 
t_envnode* sorted_merge_env(t_envnode* a, t_envnode* b)
{
    t_envnode* result = NULL;
 
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }
 
    // Compare the keys of the two nodes
    if (strcmp(a->key, b->key) <= 0) {
        result = a;
        result->next = sorted_merge_env(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge_env(a, b->next);
    }
 
    return result;
}
 
void front_back_split(t_envnode* source, t_envnode** front_ref, t_envnode** back_ref)
{
    t_envnode* fast;
    t_envnode* slow;
    slow = source;
    fast = source->next;
 
    // Move 'fast' two nodes, and move 'slow' one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    // 'slow' is before the midpoint in the list, so split it in two at that point
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

// size_t key_len = strlen(curr->key) + 1;
// size_t value_len = strlen(curr->value) + 1;
// node->key = malloc(key_len + 2); // Add 2 to the key length for the double quotation marks
// node->value = malloc(value_len);
// node->key[0] = '\"'; // Add the first double quotation mark
// memcpy(node->key + 1, curr->key, key_len - 1); // Copy the key without the null terminator
// node->key[key_len - 1] = '\"'; // Add the second double quotation mark
// memcpy(node->value, curr->value, value_len);
// t_envnode	*sort_envnode(t_envnode *lst)
// {
// 	char	*swap;
// 	t_envnode	*tmp;

// 	tmp = lst;
// 	while(lst->next != NULL)
// 	{
//         printf("lst->key %s\n", lst->key);
//         printf("lst->key->next %s\n", lst->next->key);
//         // printf("new : %ld\n", lst->key - lst->next->key);
// 		if ((ft_strcmp(lst->key, lst->next->key) > 0))
// 		{
// 			swap = lst->key;
// 			lst->key = lst->next->key;
//             printf("new : %ld\n", lst->key - lst->next->key);
// 		    lst->next->key = swap;
// 			lst = tmp;
//             // printf("lst %s\n", lst);

// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }

// int compare_cmd_wnode(char *a, char *b){
//     return (a - b);
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