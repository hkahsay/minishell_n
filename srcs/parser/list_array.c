#include "../../headers/minishell.h"

char    **create_array(t_cmd **cmd_head)
{
    int size;
    char    **array_cmd;
    int     i;
    // node = cmd_head;
    t_cmd *cmd_temp = *cmd_head;
	char	*trimmed;

    size = ft_list_size(cmd_temp);
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