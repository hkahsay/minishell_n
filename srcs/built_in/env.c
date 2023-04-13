#include"../../headers/minishell.h"
// t_envnode *ft_join_env(t_envnode **mini_env)
// {
//     t_envnode *mini_envp = *mini_env;
//     // int     i = 0;
//     while (mini_envp)
//     {
//         int length_value;

//         if (mini_envp->value)
//          length_value = (ft_strlen(mini_envp->value) + 2);
//         else
//             length_value = 2;
//         mini_envp->content = malloc(ft_strlen(mini_envp->key) + length_value); // +2 for the '=' sign and null terminator
//         if (mini_envp->content == NULL)
//         {
//             // Handle error
//             return (0);
//         }

//         strcpy(mini_envp->content, mini_envp->key); // Copy mini_envp->key to mini_envp->content
//         strcat(mini_envp->content, "="); // Append '=' to mini_envp->content
//         if (mini_envp->value != NULL)
//             strcat(mini_envp->content, mini_envp->value);

//         // printf("mini_env->content%s\n", mini_envp->content);
//         mini_envp = mini_envp->next;
//         // mini_envp = *mini_env;
//         // *mini_env = mini_envp;
//         // mini_envp = mini_envp->next;

//     }
//     mini_envp = *mini_env;
//     // printf("mini_env->content%s\n", mini_envp->content);
//     return (mini_envp);
//     // while (mini_envp)
//     // {
//     //     /* code */
//     // }
    
// }

int ft_env(char **args, t_envnode **mini_env)
{
    (void)args;
    t_envnode *mini_envp = *mini_env;
    // int     i = 0;

    // mini_envp->content = malloc(strlen(mini_envp->key) + strlen(mini_envp->value) + 2); // +2 for the '=' sign and null terminator
    if(!mini_envp)
        return(0);
    // mini_envp = ft_join_env(&mini_envp);
    // *mini_env = mini_envp;
    // printf("mini_envp->content2%s\n", (*mini_env)->content);
    // while (mini_envp->next)
    // {
    //     // while (mini_envp->content)
    //     // {
    //     //    if(mini_envp->content[i] == '=' )
    //     //     {
    //             printf("%s\n", mini_envp->content);
    //         //     i++;

    //         // }
        
    //     // if (ft_strcmp(mini_envp->content, "=") == 0)
    //     mini_envp = mini_envp->next;
    // }
    print_mini_envp(mini_envp);
    return(0);  
}
