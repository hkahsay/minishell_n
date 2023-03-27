#include "../../headers/minishell.h"

//create new linked-list
t_cmd_node	*cmd_newlst(void)
{
	t_cmd_node	*new;

	new = malloc(sizeof(t_cmd_node));
	if (!new)
		return (NULL);
	return (new);
}

//last node in the linked list
t_cmd_node	*cmd_last(t_cmd_node *cmd)
{
	while (cmd)
	{
		if (cmd->next == NULL)
			return (cmd);
		cmd = cmd->next;
	}
	return (cmd);
}

/*ajoute un nouveau node à la suite du dernier node de la liste cmd*/
void	cmd_addback(t_cmd_node **cmd, t_cmd_node *new_cmd)
{
	t_cmd_node	*last_cmd_node;

	if (*cmd == NULL)
		*cmd = new_cmd;
	else
	{
		last_cmd_node = cmd_last(*cmd);
		last_cmd_node->next = new_cmd;
	}
}

int	empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0)
		return (1);
	return (0);
}