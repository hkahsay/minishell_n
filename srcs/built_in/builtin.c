
#include"../../headers/minishell.h"

// typedef int (*builtin_func)(char **, t_envnode **);

// typedef struct s_builtin
// {
//     const char *name;
//     builtin_func func;
// } t_builtin;

// int ft_export(char **args, t_envnode **env_var)
// {
//     char	*var_name;
// 	char	*var_value;

//     printf("ft_export\n");
//     return 0;
// }


// int	export(char **args, t_envnode *env_var)
// {
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


int is_builtin(char **cmd, t_envnode *env_var)
{
    t_builtin builtin_cmds[] = {
        {"pwd", &ft_pwd},
        {"cd", &ft_cd},
        {"echo", &ft_echo},
        {"unset", &ft_unset},
        {"export", &ft_export},
        {"env", &ft_env},
        {"exit", &ft_exit},
        {NULL, NULL}
    };
	size_t i = 0;
	// printf("0\n");
	
    while (builtin_cmds[i].name != NULL && i < sizeof(builtin_cmds) / sizeof(t_builtin))
    {
		// printf("1. s[%zu] %s\n", i, builtin_cmds[i].name);
        // printf("1. cmd[0][%zu] %s\n", i, cmd[0]);
		// printf("1\n");
        if (strcmp(builtin_cmds[i].name, cmd[0]) == 0)
        {
			// printf("2\n");
            return (builtin_cmds[i].func(cmd, &env_var));
        }
		i++;
    }
    // printf("3. not builtin %s\n", cmd[0]);
    return (-1);
}


// int main(int argc, char **argv, char **env)
// {
//     if (argc == 2)
//     {
//         char **cmd = &argv[1];
//         is_builtin(cmd, env);
// 		printf("OK %s\n", cmd[0]);
      
//     }

//     return 0;
// }

// // typedef int (*builtin_func)(char **);

// // typedef enum e_builtin_type
// // {
// // 	PWD,
// // 	CD,
// // 	ECHO,
// // 	UNSET,
// // 	EXPORT,
// // 	ENV,
// // 	EXIT
// // } t_builtin_type;

// // typedef int (*builtin_func)(char **);

// typedef struct s_builtin
// {
//     const char *name;
//     builtin_func func;
// }t_builtin;

// int ft_pwd(char **args);
// int ft_cd(char **args);
// int ft_echo(char **args);
// int ft_unset(char **args);
// int ft_export(char **args);
// int ft_env(char **args);
// int ft_exit(char **args);



// int is_builtin(char **cmd)
// {
// 	char **s;
//     // int builtin_size;
// 	int i;
// 	t_builtin *builts;
// 	builts = &(t_builtin){
//     {"pwd", &ft_pwd},
//     {"cd", &ft_cd},
//     {"echo", &ft_echo},
// 	{"unset", &ft_unset},
// 	{"export", &ft_export},
// 	{"env", &ft_env},
//     {"exit", &ft_exit},
//     {NULL, NULL}
// 	};
// 	// builtin_size = 7;
// 	i = 0;
// 	// static const char *builtins_cmds[] =
// 	// 	{"pwd","cd", "echo", "unset", "export", "env", "exit", 0};
// 	s = cmd;
// 	printf("s %s\n", (char *)s[i]);	
// 	// printf("s %s\n", (char*)&cmd[i]);	
// 	while (builts->name != NULL && (i < sizeof(builts) / sizeof(t_builtin))) //(char *)s[i] != 0
// 	{
// 		printf("2. (char *)s[i] %s\n", (char *)s[i]);
// 		if (*s[i] == *cmd[0] && !strcmp((char *)s[i], builts->name))
// 		{

// 			// return(i);
// 			return (builts->func(cmd);
// 		}
// 		builts++;
// 	}
// 	return(0);
// }

// int	main(int argc, char **argv)
// {
// 	int	index;

// 	index = 0;
// 	if (argc == 2)
// 	{
// 		is_builtin(&argv[1]);
// 		// if (is_builtin(argv[1]))
// 			printf("OK %s\n", (char *)argv[1]);
// 		// else
// 		// 	printf("not builtin %s\n", argv[1]);	
// 	}
// 	return (0);
// }

// // b_func builtins[] = {
// //     &ft_pwd,
// // 	&ft_cd,
// //     &ft_echo,
// //     &ft_unset
// //     &ft_export,
// // 	&ft_env,
// //     &ft_exit
// // };

// int ft_pwd(char **args)
// {
// 	printf(R"pwd\n"RS);
// 	return (0);
// }

// int ft_cd(char **args)
// {
// 	printf(R"cd\n"RS);
// 	return (0);
// }

// int ft_echo(char **args)
// {
// 	printf(R"echo\n"RS);
// 	return (0);
// }

// int ft_unset(char **args)
// {
// 	printf(R"unset\n"RS);
// 	return (0);
// }

// int ft_export(char **args)
// {
// 	printf(R "export\n"RS);
// 	return (0);
// }

// int ft_env(char **args)
// {
// 	printf(R "env\n" RS);
// 	return (0);
// }

// int ft_exit(char **args)
// {
// 	printf(R "exit\n" RS);
// 	return (0);
// }




//  // int	ft_export(char **args)//, t_envnode *env_var
// // {
// // 	char	*var_name;
// // 	char	*var_value;
// // 	int		len;
// // 	int		i;
// // 	int		j;

// // 	var_name = strdup(env_var->key);
// // 	var_value = strdup(env_var->value);
// // 	len = ft_strlen(cmd->cmd_wnode->file);
// // 	i = 0;
// // 	j = 0;
// // 	if(is_builtin(args))
// // 	{
// // 		while (i < len && cmd->cmd_wnode->file[i] != '=' )
// // 		{
// // 			if (ft_strcmp(&cmd->cmd_wnode->file[0], "export") == 0)
// // 				var_name[i] = cmd->cmd_wnode->file[i];
// // 			i++;
// // 		}
// // 		var_name[i] = '\0';
// // 		if (i == len)
// // 		{
// // 			printf("Usage: export VAR=value\n");
// // 			return(1);
// // 		}
// // 		while (i < cmd->cmd_wnode->file[i])
// // 		{
// // 			if (ft_strcmp(&cmd->cmd_wnode->file[0], "export") == 0)
// // 				var_value[j] = cmd->cmd_wnode->file[i];
// // 			i++;
// // 			j++;
// // 		}
// // 		var_value[j] = '\0';
// // 		//-----setenv----
// // 		ft_setenv(var_name, var_value, &env_var);
// // 		printf("%s=%s", var_name, var_value);
// // 		free(var_name);
// // 		free(var_value);
// // 	return (0);

// // 	}
// // }