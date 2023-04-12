#include"../../headers/minishell.h"

// void	*add_envp_to_env(t_env **env_tail, char *envp)
// {
// 	t_env	*new_node;

// 	new_node = malloc(sizeof(t_env));
// 	if (!(new_node))
// 		return (NULL);
// 	new_node->content = envp;
// 	new_node->next = *env_tail;
// 	new_node->prev = NULL;
// 	(*env_tail)->prev = new_node;
// 	*env_tail = new_node;
// 	return (0);
// }

int ft_env(char **args, t_envnode **mini_env)
{
    (void)args;
    // char    *env_key = NULL;
    // char    *env_value = NULL;
    t_envnode   *builtin_env;

    // int i = 0;
    // printf("ft_envt1\n");
    builtin_env = malloc(sizeof(t_envnode) * 1);
    if(!builtin_env)
        return(0);
    builtin_env = *mini_env;
    // builtin_env = create_mini_envvar_node(env_key, env_value);
    while (builtin_env)
    {
         if (builtin_env->value)// != '\0'
             print_mini_envp(builtin_env);
        builtin_env = builtin_env->next;

    }
    
    // if ((*mini_env)->value && (*mini_env)->value[0] != '\0')// != '\0'
    // {
    //     printf("ft_envt2\n");
        // print_envp_nvalue(*mini_env);

    // }
    // else
    // {
    //     printf("ft_envt3\n");
    // }
    // printf("ft_envt3\n");
    // print_mini_envp(*mini_env);
    // printf("ft_envt4\n");
	// int i = 0;

    // t_envnode* current = *mini_env;
    // while (current)
    // {
    //     printf("%s\n", current->value);
    //     // while (current->value[i])
    //     // {
    //     //     if(current->value[i] == '=')
    //     //     {
    //             printf("%s%s", current->key, current->value); // Assuming key and value are strings
    //     //     }
    //     //     // else if (current->key != NULL && current->value == NULL)
    //     //     //     printf("21%s\n", current->key); // Assuming key and value are strings
    //     //     i++;
    //     // }
    //      current = current->next;
    // }
	// printf("%d\n", i);
    return 0;
}

// int check_env_complete(t_envnode* env_list) {
//     t_envnode* current = env_list;
//     while (current != NULL) {
//         if (current->key == NULL || current->value == NULL) { // Check if either key or value is NULL
//             return 0; // Return 0 if any member does not have both key and value
//         }
//         current = current->next;
//     }
//     return 1; // Return 1 if all members have both key and value
// }

// void print_mini_envp(t_envnode *temp)
// {
// 	int i = 0;

// 	while (temp)
// 	{
// 		printf("LIST: %s=%s\n", temp->key, temp->value);
// 		temp = temp->next;
// 		i++;
// 	}
// 	printf("%d\n", i);
// }