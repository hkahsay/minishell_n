#include"../../headers/minishell.h"

void print_mini_envp(t_envnode *temp)
{
	// int i = 0;

	while (temp)
	{
		// printf("VALUE: %s\n", temp->value);
			// if (temp->value[0] == '=')
				printf("%s%s\n", temp->key, temp->value);
		// if (temp->key == '=')
		temp = temp->next;
		// i++;
	}
	// printf("%d\n", i);
}

void print_envp_nvalue(t_envnode *mini_env)
{
	int i = 0;

    while (mini_env)
    {
        if (mini_env->value && mini_env->value[0] != '\0')
        {
            printf("%s", mini_env->key);
            if (mini_env->value)
                printf("%s", mini_env->value);
            printf("\n");
        }
		i++;
        mini_env = mini_env->next;
    }
	printf("%d\n", i);
}


void print_ex_envp(t_envnode *mini_env, char **cmd_arg)
{
	int i = 0;
	(void)cmd_arg;

	while (mini_env != NULL)
	{
		printf("declare -x %s%s\n", mini_env->key, mini_env->value);
		i++;
		mini_env = mini_env->next;
	}
	printf("%d\n", i);
}

void print_ex_no_value(t_envnode *mini_env)
{
    while (mini_env)
    {
        if (mini_env->value == NULL) //mini_env->value && 
        {
            printf("%s", mini_env->key);
            printf("\n");
        }
		if (mini_env->value)
			printf("%s%s\n", mini_env->key, mini_env->value);
        mini_env = mini_env->next;
    }
}