#include"../../headers/minishell.h"

int *ft_echo(char  **str, int n)
{
    int  i;
    int  j;

    j = 0;
    i = n;
    if (n == 0)
        i = 2;
    while (str[i])
    {
        while (str[i][j])
        {
            if (str[i][j] != '"' && str[i][j] != '\'')
                ft_putchar_fd(str[i][j], 1);
            else if (str[i][j] == '"' &&
                str[i][j] == '\\' && str[i][j] != '\'')
                ft_putchar_fd(str[i][j], 1);
            j++;
        }
        i++;
        ft_putchar_fd(' ', 1);
    }
    if(n)
        ft_putchar_fd('\n', 1);
    return(0);
}

//Returns one if paramater has a flag -n

int	ft_n_flag(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strlen(arg) >= 2)
	{
		if (ft_gc_strtrim(arg, " ")[0] == '-')
			return (ft_gc_strtrim(arg, " ")[1] == 'n');
	}
	return (0);
}

// int ft_echo(char **args, t_envnode *env)
// {
//     int i = 1;  // Start with the first argument (skip "echo")

//     // Check for the "-n" flag
//     if (args[i] && ft_strcmp(args[i], "-n") == 0)
//         i++;  // Skip the flag

//     // Print each argument followed by a space, except the last one
//     while (args[i])
//     {
//         ft_putstr(args[i]);
//         if (args[i + 1])
//             ft_putchar(' ');
//         i++;
//     }
//     // Print a newline character unless the "-n" flag was used
//     if (args[1] && ft_strcmp(args[1], "-n") != 0)
//         ft_putchar('\n');
//     return 0;  // Return success
// }
