#include"../../headers/minishell.h"

// int is_builtins(t_cmd   *cmd)
// {
//     t_envnode   *env = NULL;
//     int builtin;
//     while (cmd)
//     {
//         ft_tolower_str(cmd);
//         builtin = check_builtin_type(cmd, "pwd", PWD);
//             if (builtin)
//                 return (builtin);
//             printf("pwd");
//         builtin = check_builtin_type(cmd, "cd", CD);
//             if (builtin)
//                 return (builtin);
//         builtin = check_builtin_type(cmd, "echo", CMD_ECHO);
//             // exc_echo(env, cmd);
//             if (builtin)
//                 return (builtin);
//         builtin = check_builtin_type(cmd, "unset", UNSET);
//             // exc_unset(env, cmd);
//             if (builtin)
//                 return (builtin);
//         builtin = check_builtin_type(cmd, "export", EXPORT);
//             // exc_export(env, cmd);
//             if (builtin)
//                 return (builtin);
//         builtin = check_builtin_type(cmd, "env", ENV);
//             // exc_env(env,cmd);
//             if (builtin)
//                 return (builtin);
//         builtin = check_builtin_type(cmd, "exit", EXIT);
//             // exc_exit(env, cmd);
//             if (builtin)
//                 return (builtin);
//         else
//         {
//             perror("command not found");
//             // or check 
//             return (1);
//         }
//     }
//     return (0);
// }

//  static int    check_builtin_type(t_redir_args *args, char *str, int type)
//  {
//     t_redir_args    *string = new_redir_args(str, type);
//     if (!str)
//         return (-1);
//     if(!args || !string)
//         return (0);
//     if(ft_strncm(args->args, string->args, ))
//  }

 