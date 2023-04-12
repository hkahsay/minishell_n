#include "../../headers/minishell.h"      

t_envnode	*envdup(t_envnode *prev, t_envnode **mini_env)
{
	t_envnode	*node;

	if (!(*mini_env))
		return (NULL);
	node = create_mini_envvar_node((*mini_env)->key, (*mini_env)->value);
	if (!node)
		return (NULL);
	printf("NODE: %s = %s\n", (*mini_env)->key, (*mini_env)->value);
	node->prev = prev;
	if ((*mini_env)->next)
	{
		node->next = envdup(node, &(*mini_env)->next);
		if (!node->next)
		{
			while (node->prev)
				node = node->prev;
			free_mini_envp(node);
			return (NULL);
		}
	}
	return (node);
}

t_envnode	*export_no_cmd(t_envnode **mini_env)
{
	return (envdup(NULL, mini_env));
}

int ft_export(char **cmd_args, t_envnode **mini_env)
{
	char	*new_key;
	char	*new_value;
	int		i;
	// t_cmd	*cmds = NULL;
	// int	len = 0;
    t_envnode *new_env_var = NULL;
	i = 0;
	if (cmd_args[1] == NULL && mini_env)
	{
		new_env_var = export_no_cmd(mini_env);
		// printf("Mini env: %p\n", (*mini_env)->value);
		// printf("New env var: %p\n", new_env_var->value);
		// print_ex_envp(new_env_var, cmd_args);
		ft_envnode_sort(new_env_var);
		printf("Sorted: %s = %s\n", new_env_var->key, new_env_var->value);
        // print_mini_envp(*mini_env);
		print_ex_envp(new_env_var, cmd_args);
		printf(YELLOW"only expo\n"RS);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	}
	if (cmd_args[1] && ft_strchr(cmd_args[1], '='))//ft_strchr(const char	*s, int c)
	{
		while (cmd_args[1][i] != '=')
		{
			printf(BLUE "*cmd_args[1] %c\n"RS, cmd_args[1][i]);
			printf(R"there is == sign in key\n"RS);
			i++;
		}
		new_key = ft_substr((char *)cmd_args[1], 0, i);
		// printf(R"new_key: %s\n"RS, new_key);

		i++;
		
		// printf("i: %d\n", i);
		int	j = 0;
		while (cmd_args[1][j] != '\0')
		{
			printf(GREEN"*cmd_args[1] %c\n"RS, cmd_args[1][j]);
			printf(OR"there is == sign in value\n"RS);
			j++;
		}
		new_value = ft_substr((char *)cmd_args[1], i, j);
		// printf(R"new_value: %s\n"RS, new_value);
		ft_setenv(new_key, new_value, mini_env);
		print_mini_envp(*mini_env);
	}
	if (cmd_args[1] && !ft_strchr(cmd_args[1], '='))
	{
		 // Extract key from cmd_args[1]
        new_key = ft_strdup(cmd_args[1]);
        new_env_var = find_env_var(new_key, mini_env);
		printf(GREEN"there is != sign\n"RS);
        if (new_env_var)
        {
            // If environment variable already exists, set its value to empty string
            free(new_env_var->value);
            new_env_var->value = ft_strdup("");//ft_strdup("");
			// printf(BLUE"already exist var != sign\n"RS);
        	// print_ex_no_value(*mini_env);

        }
		else
        {
            // If environment variable does not exist, create a new one with empty value
			// printf(OL"not exsist != sign\n"RS);
            new_value = ft_strdup(""); //ft_strdup("");
            new_env_var = create_mini_envvar_node(new_key, new_value);
            ft_add_envlist(new_env_var, mini_env);
        	// print_ex_no_value(*mini_env);

        }
		printf(R"print all cmd_args and return new prompt\n"RS);
        // print_ex_no_value(*mini_env);
	}
    return (0);
}








// typedef struct s_builtin {
//     const char *key;
//     builtin_func func;
// } t_builtin;

// int ft_pwd(char **args);
// int ft_cd(char **args);
// int ft_echo(char **args);
// int ft_unset(char **args);
// int ft_export(char **args);
// int ft_env(char **args);
// int ft_exit(char **args);

// int is_builtin(char **cmd)
// {
//     char **s = cmd;
//     t_builtin *builts = &(t_builtin){
//         {"pwd", &ft_pwd},
//         {"cd", &ft_cd},
//         {"echo", &ft_echo},
//         {"unset", &ft_unset},
//         {"export", &ft_export},
//         {"env", &ft_env},
//         {"exit", &ft_exit},
//         {NULL, NULL}
//     };
//     int i = 0;
//     while (builts->key != NULL && i < sizeof(builtons_cmds) / sizeof(t_builtin))
//     {
//         if (*s[i] == *cmd[0] && !strcmp(s[i], builts->key))
//         {
//             return builts->func(cmd);
//         }
//         builts++;
//     }
//     return 0;
// }

// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         int result = is_builtin(&argv[1]);
//         if (result != 0) {
//             printf("OK %s\n", argv[1]);
//         } else {
//             printf("not builtin %s\n", argv[1]);
//         }
//     }
//     return 0;
// }
