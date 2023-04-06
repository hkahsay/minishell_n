#include "../../headers/minishell.h"

int ft_export(char **cmd_args, t_envnode **mini_env)
{
    printf(R"ft_export\n"RS);
	char	*new_key;
	char	*new_value;
	int		i;
	// int	len = 0;
	// (void)env_var;
    t_envnode *new_env_var = NULL;
	// (void)new_env_var;
	i = 0;
	printf("*cmd_args[1] %s\n", cmd_args[1]);
	while (cmd_args[1][i] != '=')
	{
		printf(BLUE "*cmd_args[1] %c\n"RS, cmd_args[1][i]);
		i++;
	}
	new_key = ft_substr((char *)cmd_args[1], 0, i);
	printf(R"new_key: %s\n"RS, new_key);

	i++;
	
	printf("i: %d\n", i);
	int	j = 0;
	while (cmd_args[1][j] != '\0')
	{
		printf(GREEN"*cmd_args[1] %c\n"RS, cmd_args[1][j]);
		j++;
	}
	new_value = ft_substr((char *)cmd_args[1], i, j);
	printf(R"new_value: %s\n"RS, new_value);

	new_env_var = create_mini_envvar_node(new_key, new_value);
	ft_add_envlist(new_env_var, mini_env);
	print_mini_envp(*mini_env);
    return (0);
}


// int	export(char **args, t_envnode *env_var)
// { 												export VAR=args
// 	char	*var_name;
// 	char	*var_value;
// 	int		len;
// 	int		i;
// 	int		j;

// 	//  if (argc < 2) {
//     //     printf("Usage: export VAR=value\n");
//     //     return 1;
//     // }
// 	var_name = strdup(env_var->key);
// 	var_value = strdup(env_var->value);
// 	len = ft_strlen(cmd->cmd_args->args);
// 	i = 0;
// 	j = 0;
// 	while (i < len && cmd->cmd_args->args[i] != '=' )
// 	{
// 		if (ft_strcmp(&cmd->cmd_args->args[0], "export") == 0)
// 			var_name[i] = cmd->cmd_args->args[i];
// 		i++;
// 	}
// 	var_name[i] = '\0';
// 	if (i == len)
// 	{
// 		printf("Usage: export VAR=value\n");
// 		return(1);
// 	}
// 	while (i < cmd->cmd_args->args[i])
// 	{
// 		if (ft_strcmp(&cmd->cmd_args->args[0], "export") == 0)
// 			var_value[j] = cmd->cmd_args->args[i];
// 		i++;
// 		j++;
// 	}
// 	var_value[j] = '\0';
// 	//-----setenv----
// 	ft_setenv(var_name, var_value, &env_var);
// 	printf("%s=%s", var_name, var_value);
// 	free(var_name);
// 	free(var_value);
// 	return (0);
// }





// typedef struct s_builtin {
//     const char *name;
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
//     while (builts->name != NULL && i < sizeof(builtons_cmds) / sizeof(t_builtin))
//     {
//         if (*s[i] == *cmd[0] && !strcmp(s[i], builts->name))
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
