#include "../../headers/minishell.h"

static t_redir_args	*init_args(t_redir_args *new_redir_args)
{
	new_redir_args = malloc(sizeof(t_redir_args) * 1);
	if (!new_redir_args)
		return (NULL);
	new_redir_args->type = 0;
	new_redir_args->args = NULL;
	return (new_redir_args);
}

static t_cmd_node	*init_cmd(t_cmd_node *new_cmd)
{
	new_cmd = malloc(sizeof(t_cmd_node) * 1);
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd_args = 0;
	new_cmd->cmd_redir = NULL;
	return (new_cmd);
}

static t_redir_args *new_cmd(char *content, t_toktype type)
{
    t_cmd_node *new_cmds = NULL;
	new_cmds = init_cmds(new_cmds);
	printf("init cmds ok\n");

	printf("2 new_cmds->content: %s\n", content);
	printf("2 new_cmds->id: %d\n", type);
    // new_cmds = malloc(sizeof(t_cmd));
    // if (!new_cmds)
    //     return (NULL);
    new_cmds->cmd_args = ft_strdup(content);
    printf(R "new_cmds->content: %s\n" RS, new_cmds->cmd_args);
    new_cmds->cmd_redir = type;
    printf(R "new_cmds->id: %d\n" RS, new_cmds->cmd_redir);
    return (new_cmds);
}

static t_redir_args *new_redir_args(char *content, t_toktype type)
{
    t_redir_args *new_args = NULL;
	new_args = init_args(new_args);
	printf("init args ok\n");

	printf("2 new_args->content: %s\n", content);
	printf("2 new_args->id: %d\n", type);
    // new_args = malloc(sizeof(t_redir_args));
    // if (!new_args)
    //     return (NULL);
    new_args->args = ft_strdup(content);
    printf(R "new_args->content: %s\n" RS, new_args->args);
    new_args->type = type;
    printf(R "new_args->id: %d\n" RS, new_args->type);
    new_args->next = NULL;
    return (new_args);
}

// t_token *new_token(char *content, t_toktype type)
// {
//     t_token *new_token;

//     new_token = malloc(sizeof(t_token));
//     if (!new_token)
//         return (NULL);
//     new_token->content = ft_strdup(content);
//     printf("new_token->content: %s\n", new_token->content);
//     new_token->id = type;
//     printf("new_token->id: %d\n", new_token->id);
//     new_token->next = NULL;
//     return (new_token);
// }

void print_t_redir_args(t_redir_args *temp)
{
	int i = 0;

	printf("i: %d\n", i);
	while (temp)
	{
		printf("CMD t_redir_args: %s=%d\n", temp->args, temp->type);
		temp = temp->next;
		i++;
	}
	printf("%d\n", i);
}

static t_redir_args *add_args_to_list(t_redir_args **head_args, int type, char *content) //t_redir_args *args, 
{
	t_redir_args *temp = NULL;

	printf("new_args->content: %s\n", content);
	printf("new_args->id: %d\n", type);
   
    t_redir_args *args = new_redir_args(content, type);

    if (*head_args == NULL)
    {
        *head_args = args;
    }
    else
    {
        t_redir_args *current = *head_args;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = args;
    }
	temp = *head_args;
	print_t_redir_args(temp);
	return (*head_args);
}

t_redir_args	*eval_token(t_token *head)
{
	// int		i;
	// int	counter;
	t_redir_args *args = NULL;
	t_cmd_node *cmd = NULL;
	t_token *head_ptr = NULL;
	
	// args = init_args(args);
	// printf("init args ok\n");
	head_ptr = head;
	while (head_ptr)
	{
		if (head_ptr->id != TOK_PIPE)
		{
			if (head_ptr->id == TOK_WORD || head_ptr->id == TOK_D_QUOTE || head_ptr->id == TOK_S_QUOTE)
			{
				cmd->cmd_args = add_args_to_list(&args, head_ptr->id, head_ptr->content);
				printf("add_args ok\n");	
			}
			else
			{
				cmd->cmd_redir = add_args_to_list(&args, head_ptr->id, head_ptr->content);
				printf("add_redi ok\n");	
			}
		}
		// else
		head_ptr = head_ptr->next;
	}
	return (args);
	
}

t_cmd	parse(t_token *head)
{
	// t_cmd_node	*cmd;
	// t_cmd_node	*single_cmd;

	// single_cmd = NULL;
	// single_cmd = init_cmd(single_cmd);
	print_redir_args(head);
	// if (!head)
	// 	return (NULL);
	printf("Print token OK\n");
	token_analysis(head, eval_token);
	printf("Returned from token_analysis OK\n");	
}





// static t_cmd_node	*init_cmd(t_cmd_node *new_cmd, int size)
// {
// 	new_cmd = malloc(sizeof(t_cmd_node) * 1);
// 	if (!new_cmd)
// 		return (NULL);
// 	new_cmd->cmd_args = malloc(sizeof(char *) * (size + 1));
// 	new_cmd->cmd_args[size] = NULL;
// 	if (!new_cmd->cmd_args)
// 		return (0);
// 	new_cmd->cmd_redir = init_redir(new_cmd->cmd_redir);
// 	return (new_cmd);	
// }   

//simple_cmd_token_analasis-----

// count number of word type in the list


// t_cmd_node	*parse(char *line, t_cmd_node *first_cmd)
// {
// 	char		*temp;
// 	t_redir_args		*token;
// 	t_toktype	type;
	

// 	token = new_token(line,type);
// 	temp = skip_spaces(line);
// 	while (!empty_str(temp))
// 	{
// 		temp = init_redir_args(token);
// 		if (inter(temp))
// 		{
// 			add_token(token, temp, type);
// 			token = token->next;
// 			// temp = get_next_redir_args(token, temp);
// 			// continue ;
// 		}
// 		// free(temp);
// 		// return (ft_free(token));
// 	}
// 	free(temp);
// 	// if (!valid_syntax(ms_head_list(token)))
	
// 	return (first_cmd);
// }
/*renvoie la string de l'input en retirant le morceau de string
qui vient d'etre copié dans le token précédent*/
// char	*ms_get_next_redir_args(t_redir_args *token, char *temp)
// {
// 	char	*str;

// 	if (temp)
// 	{
// 		str = temp;
// 		str = ft_substr(token->content, token->id,
// 				ft_strlen(token->content) - token->id);
// 		free(temp);
// 		return (str);
// 	}
// 	return (NULL);
// }
