#include"../../headers/minishell.h"

int ft_exit(char **args, t_envnode **mini_env)
{
    int	i;

	i = 0;
	if (args != NULL)
	{
		i = ft_atoi(*args);
		printf("exit\n");
		// free(mini_env);
		exit (i);
	}
	else
	{
		printf("exit\n");
		free(mini_env);
		// exit (g_status);
	}
    return (0);
}

// int ft_env(char **args, t_envnode **mini_env)
// {
//     // (void)args;
//     t_envnode *mini_envp = *mini_env;
//     int     i = 0;
//     char    *content;


//     // printf("mini_envp->value[0]%c\n", mini_envp->value[0]);
//     content = init_content(&mini_envp);
//     if(!mini_envp)
//         return(0);
//     while (mini_envp)
//     {
//         printf("arg[1] %s\n", args[1]);
//         if (ft_strchr(content, '='))
//         {
//             printf("mini_envp->value from print%s\n", mini_envp->value);
//             printf("%s=%s\n", mini_envp->key, mini_envp->value);
//         }
//         i++;
//         mini_envp = mini_envp->next;
//     }
//     return(0);  
// }