
#include"../../headers/minishell.h"

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
	
    while (builtin_cmds[i].name != NULL && i < sizeof(builtin_cmds) / sizeof(t_builtin))
    {
        if (ft_strcmp(builtin_cmds[i].name, cmd[0]) == 0)
        {
            return (builtin_cmds[i].func(cmd, &env_var));
        }
		i++;
    }
    return (-1);
}

