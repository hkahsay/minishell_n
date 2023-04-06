#include "../../headers/minishell.h"      

static void print_ex_no_value(t_envnode *mini_env)
{
    while (mini_env)
    {
        if (mini_env->value && mini_env->value[0] != '\0')
        {
            printf("%s", mini_env->key);
            if (mini_env->value)
                printf("%s", mini_env->value);
            printf("\n");
        }
        mini_env = mini_env->next;
    }
}

static int	export_no_cmd(t_envnode **mini_env)
{
	int i = 0;

	// Count the number of environment variables in mini_env
	int env_count = 0;
	t_envnode *curr = *mini_env;
	while (curr != NULL)
	{
		env_count++;
		curr = curr->next;
	}

	// Create a new linked list with the same environment variables
	t_envnode *new_env = NULL;
	curr = *mini_env;
	while (i < env_count)
	{
		t_envnode *node = malloc(sizeof(t_envnode));
		size_t key_len = strlen(curr->key) + 1;
		size_t value_len = strlen(curr->value) + 1;
		node->key = malloc(key_len + 2);
		node->value = malloc(value_len);
		node->key[0] = '\"'; 
		// printf("node->key[1] %c\n", node->key[1]);
		memcpy(node->key + 1, curr->key, key_len - 1);
		node->key[key_len - 1] = '\"';
		memcpy(node->value, curr->value, value_len);
		node->next = new_env;
		new_env = node;
		curr = curr->next;
		i++;
	}
	// node->key[0] = '\"'; 
	// node->key[key_len - 1] = '\"';
	// print_ex_envp(*mini_env);
	// merge_sort(mini_env);
	while (new_env != NULL)
	{
		t_envnode *node = new_env;
		new_env = new_env->next;
		free(node->key);
		free(node->value);
		free(node);
	}
	return (0);
}

void print_ex_envp(t_envnode *temp)
{
	// int i = 0;

	while (temp)
	{
		export_no_cmd(&temp);
		merge_sort_env(&temp);
		printf("declare -x %s=%s\n", temp->key, temp->value);
		temp = temp->next;
		// i++;
	}
	// printf("%d\n", i);
}

int ft_export(char **cmd_args, t_envnode **mini_env)
{
	char	*new_key;
	char	*new_value;
	int		i;
	// t_cmd	*cmds = NULL;
	// int	len = 0;
    t_envnode *new_env_var = NULL;
	i = 0;
	if (cmd_args[1] == NULL && mini_env)
		print_ex_envp(*mini_env);
	if (cmd_args[1] && ft_strchr(cmd_args[1], '='))//ft_strchr(const char	*s, int c)
	{
		while (cmd_args[1][i] != '=')
		{
			printf(BLUE "*cmd_args[1] %c\n"RS, cmd_args[1][i]);
			i++;
		}
		new_key = ft_substr((char *)cmd_args[1], 0, i);
		// printf(R"new_key: %s\n"RS, new_key);

		i++;
		
		// printf("i: %d\n", i);
		int	j = 0;
		while (cmd_args[1][j] != '\0')
		{
			printf(GREEN"*cmd_args[1] %c\n"RS, cmd_args[1][j]);
			j++;
		}
		new_value = ft_substr((char *)cmd_args[1], i, j);
		// printf(R"new_value: %s\n"RS, new_value);
		ft_setenv(new_key, new_value, mini_env);
		print_ex_envp(*mini_env);
	}
	if (cmd_args[1] && !ft_strchr(cmd_args[1], '='))
	{
		 // Extract key from cmd_args[1]
        new_key = ft_strdup(cmd_args[1]);
        new_env_var = find_env_var(new_key, mini_env);

        if (new_env_var)
        {
            // If environment variable already exists, set its value to empty string
            free(new_env_var->value);
            new_env_var->value = ft_strdup("");
        	// print_ex_no_value(*mini_env);

        }
		  else
        {
            // If environment variable does not exist, create a new one with empty value
            new_value = ft_strdup("");
            new_env_var = create_mini_envvar_node(new_key, new_value);
            ft_add_envlist(new_env_var, mini_env);
        	print_ex_no_value(*mini_env);

        }

        // print_ex_no_value(*mini_env);
	}
    return (0);
}








// typedef struct s_builtin {
//     const char *key;
//     builtin_func func;
// } t_builtin;

// int ft_pwd(char **args);
// int ft_cd(char **args);
// int ft_echo(char **args);
// int ft_unset(char **args);
// int ft_export(char **args);
// int ft_env(char **args);
// int ft_exit(char **args);

// int is_builtin(char **cmd)
// {
//     char **s = cmd;
//     t_builtin *builts = &(t_builtin){
//         {"pwd", &ft_pwd},
//         {"cd", &ft_cd},
//         {"echo", &ft_echo},
//         {"unset", &ft_unset},
//         {"export", &ft_export},
//         {"env", &ft_env},
//         {"exit", &ft_exit},
//         {NULL, NULL}
//     };
//     int i = 0;
//     while (builts->key != NULL && i < sizeof(builtons_cmds) / sizeof(t_builtin))
//     {
//         if (*s[i] == *cmd[0] && !strcmp(s[i], builts->key))
//         {
//             return builts->func(cmd);
//         }
//         builts++;
//     }
//     return 0;
// }

// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         int result = is_builtin(&argv[1]);
//         if (result != 0) {
//             printf("OK %s\n", argv[1]);
//         } else {
//             printf("not builtin %s\n", argv[1]);
//         }
//     }
//     return 0;
// }
