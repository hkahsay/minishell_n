#include"../../headers/minishell.h"

int ft_env(char **args, t_envnode **env_var)
{
    (void)args;
    // (void)env_var;
    print_mini_envp(*env_var);

    return 0;
}