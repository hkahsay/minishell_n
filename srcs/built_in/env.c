#include"../../headers/minishell.h"

int ft_env(char **args, t_envnode **mini_env)
{
    (void)args;
    int     i = 0;


    if(!mini_env)
        return(0);
    while ((*mini_env)->key && (*mini_env)->value)
    {
        if ((*mini_env)->value[i] == '=')
        {
            print_mini_envp((*mini_env));
            printf("env is ok\n");
            break;
        }
        i++;
        (*mini_env) = (*mini_env)->prev;
    }
    return(0);  
}