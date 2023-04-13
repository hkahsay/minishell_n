#include"../../headers/minishell.h"

int	ft_cd(char **args, t_envnode **mini_env)
{
    char cwd[1024];

	t_envnode	*env_var = NULL;
	if (!args[1])
	{
		env_var = find_env_var("HOME", mini_env);
        if (!env_var)
        {
            fprintf(stderr, "cd: HOME environment variable not set\n");
            return (1);
        }
        // if (chdir((const char *)env_var))
        // {
        //     perror("cd");
        //     return (1);
        // }
    }
    else
    {
        if (chdir(args[1]))
        {
            perror("cd");
            return (1);
        }
    }
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        return 1;
    }
	ft_setenv("PWD", cwd, (*mini_env)->content, &env_var);
    printf ("env_var%s\n", env_var->value);
    return (0);
}


// int cd_builtin(char **cmd_args, char **envp) {
//     // If no argument is given, change directory to HOME
//     if (cmd_args[1] == NULL) {
//         const char *home_dir = getenv("HOME");
//         if (home_dir == NULL) {
//             fprintf(stderr, "cd: HOME environment variable not set\n");
//             return 1;
//         }
//         if (chdir(home_dir) != 0) {
//             perror("cd");
//             return 1;
//         }
//     } else {
//         // Change directory to the specified path
//         if (chdir(cmd_args[1]) != 0) {
//             perror("cd");
//             return 1;
//         }
//     }

//     // Update the PWD environment variable
//     char cwd[1024];
//     if (getcwd(cwd, sizeof(cwd)) == NULL) {
//         perror("getcwd");
//         return 1;
//     }
//     setenv("PWD", cwd, 1);

//     return 0;
// }
// int	b_cd(t_envnode *var, char *input)
// {
// 	if (strcmp(input, "cd") == 0)
// 	{
// 		printf("%s\n", find_env_name(var, "HOME"));
// 	}
// 	else if (strcmp(input, "~") == 0)
// 	{
// 		printf("%s\n", find_env_name(var, "HOME"));
// 	}
// 	// else if (strncmp(input, "cd ..", 5) == 0)
// 	// {
// 	// 	parse_cd(var, input);
// 	// }
// 	else 
// 		printf("Command not found: %s\n", input);
// 	return (0);
// }


