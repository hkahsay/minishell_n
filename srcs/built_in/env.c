#include"../../headers/minishell.h"

static void print_envp_nvalue(t_envnode *mini_env)
{
    while (mini_env)
    {
        if (mini_env->value && mini_env->value[0] != '\0')
        {
            printf("%s", mini_env->key);
            if (mini_env->value)
                printf("=%s", mini_env->value);
            printf("\n");
        }
        mini_env = mini_env->next;
    }
}

int ft_env(char **args, t_envnode **mini_env)
{
    (void)args;
    if ((*mini_env)->value && (*mini_env)->value[0] != '\0')
        print_envp_nvalue(*mini_env);
    print_mini_envp(*mini_env);
    return 0;
}
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