#include"../../headers/minishell.h"

// char *ft_echo(t_envnode *env_var)
// {
//     char *path;
//     t_cmd   *cmd;


// }
int ft_echo(char **args, t_envnode *env)
{
    int i = 1;  // Start with the first argument (skip "echo")

    // Check for the "-n" flag
    if (args[i] && ft_strcmp(args[i], "-n") == 0)
        i++;  // Skip the flag

    // Print each argument followed by a space, except the last one
    while (args[i])
    {
        ft_putstr(args[i]);
        if (args[i + 1])
            ft_putchar(' ');
        i++;
    }
    // Print a newline character unless the "-n" flag was used
    if (args[1] && ft_strcmp(args[1], "-n") != 0)
        ft_putchar('\n');
    return 0;  // Return success
}
