#include "../../headers/minishell.h"

#include <stdlib.h>
#include <string.h>

// Definition of linked list node for environment variables
// typedef struct EnvVar {
//     char *name;
//     char *value;
//     struct EnvVar *next;
// } EnvVar;

// int main(int argc, char **argv, EnvVar **mini_env) {
//     // Check if args[1] is null
//     if (argv[1] == NULL) {
//         // Count the number of environment variables in mini_env
//         int env_count = 0;
//         EnvVar *curr = *mini_env;
//         while (curr != NULL) {
//             env_count++;
//             curr = curr->next;
//         }

//         // Create a new linked list with the same environment variables
//         EnvVar *new_env = NULL;
//         curr = *mini_env;
//         for (int i = 0; i < env_count; i++) {
//             EnvVar *node = malloc(sizeof(EnvVar));
//             size_t name_len = strlen(curr->name) + 1;
//             size_t value_len = strlen(curr->value) + 1;
//             node->name = malloc(name_len);
//             node->value = malloc(value_len);
//             memcpy(node->name, curr->name, name_len);
//             memcpy(node->value, curr->value, value_len);
//             node->next = new_env;
//             new_env = node;
//             curr = curr->next;
//         }

//         // Do something with the new environment variable linked list
//         // ...

//         // Free the memory allocated for the new linked list
//         while (new_env != NULL) {
//             EnvVar *node = new_env;
//             new_env = new_env->next;
//             free(node->name);
//             free(node->value);
//             free(node);
//         }
//     }

//     return 0;
// }









void print_mini_envp(t_envnode *temp)
{
	int i = 0;

	while (temp)
	{
		printf("LIST: %s=%s\n", temp->key, temp->value);
		temp = temp->next;
		i++;
	}
	printf("%d\n", i);
}


void free_mini_envp(t_envnode *head)
{
	t_envnode *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

t_envnode *create_mini_envvar_node(char *key, char *value)//, int i
{
	t_envnode *my_node = NULL;

	my_node = malloc(sizeof(t_envnode) * 1);
	if (!my_node)
		return (NULL);
	// printf("&new_env_var %p\n", new_env_var);
	my_node->key = ft_strdup(key);
	if (!my_node->key)
	{
		free(my_node);
		return (NULL);
	}
	my_node->value = ft_strdup(value);
	if (!my_node->value)
	{
		free(my_node->key);
		free(my_node);
		return (NULL);
	}
	my_node->prev = NULL;
	my_node->next = NULL;
	// printf("nodes %d OK %s = %s\n", my_node->key, my_node->value);
	return (my_node);
}

t_envnode *duplicate_env(char **envp) // fnct returns a starting address of the linked list env
{
	// char **envp_var;
	char *key;
	char *value;
	t_envnode *node = NULL;
	t_envnode *head = NULL;
	t_envnode *temp = NULL;
	
	int i = 0;
	int j = 0;
	//hello from Nicole
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		// printf("j avant '=': %d\n", j);
		key = ft_substr(envp[i], 0, j);
		// printf("%s\n", key);
		value = ft_substr(envp[i], (j + 1), ft_strlen(envp[i]));
		// printf("%s\n", value);
		// envp_var = ft_split(envp[i], '=');
		// key = ft_strdup(envp_var[0]);
		// value = ft_strdup(envp_var[1]);
		// printf("%d %s %s\n", (envp_lines + 1), key, value);
		node = create_mini_envvar_node(key, value);
		// printf("Node %d OK\n", i);
		// usleep(100000000);
		if (!node)
			return (NULL);
		if (head == NULL)
			head = node;
		else
		{
			temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = node;
			node->prev = temp;
			temp = node;
		}
		// free(key);
		// free(value);
		i++;
	}
	// printf("envp[i] i: %d\n", i);
	return (head);
}
