#include"../../headers/minishell.h"

int ft_env(char **args, t_envnode **mini_env)
{
    (void)args;
    t_envnode *mini_envp = *mini_env;
    // int     i = 0;


    if(!mini_env)
        return(0);
    while ((*mini_env)->key && (*mini_env)->value)
    {
        if (mini_envp->value[0] == '=')
        {
            printf("%s%s\n", mini_envp->key, mini_envp->value);
        }
        // i++;
        mini_envp = mini_envp->next;
    }
    return(0);  
}