#include"../../headers/minishell.h"

// int	mini_pwd(void)
// {
// 	char	*buf;

// 	buf = getcwd(NULL, 0);
// 	ft_putendl_fd(buf, 1);
// 	free(buf);
// 	return (0);
// }
//The buffer size of 4096 is commonly used as 
//a default value for storing the current working directory
// path because it is a multiple of the typical filesystem
//block size (e.g., 512 or 1024 bytes), and it is a power of two. 
int	ft_pwd(void)
{
	char	*str;

	str = malloc(sizeof(char)* 4096);
	if (!str)
		return(0);
	str = getcwd(str, 4096);
	if (!str)
		return(1);
	printf("%s\n", str);
	return (0);
}
// int	mini_pwd2(t_envnode *env_list)
// {
// 	t_envnode	*curr_var;
// 	char		*cwd;

// 	cwd = getcwd(NULL, 0);
// 	// printf("pwd recived %s\n", cwd);
// 	curr_var = env_list;
// 	printf(R"00curr_var %s\n"RS, curr_var->key);
// 	while (curr_var != 0)
// 	{
// 		if (strcmp(curr_var->key, "PWD") == 0)
// 		{
// 			printf(R"curr_var %s\n"RS, curr_var->key);
// 			if (strcmp(curr_var->value, cwd) == 0)
// 			{
// 				// printf("ggcurr_var %s\n", curr_var->key);
// 				printf("%s\n", curr_var->value);
// 				return (0);
// 			}
// 			else
// 			{
// 				free(curr_var->value);
// 				curr_var->value = strdup(cwd);
// 				printf(YELLOW"%s\n"RS, curr_var->value);
// 				return (0);
// 			}
// 		}
// 		curr_var = curr_var->next;
// 	}
// 	return (0);
// }

// int	mini_pwd2(t_envnode *env_list)
// {
// 	t_envnode	*curr_var;
// 	char		*cwd;

// 	cwd = getcwd(NULL, 0);
// 	printf("pwd recived %s\n", cwd);
// 	curr_var = env_list;
// 	while (curr_var != 0)//curr_var != 0)
// 	{
// 		printf("ggcurr_var %s\n", curr_var->key);
// 		if (strcmp(curr_var->key, "PWD") == 0)
// 		{
// 			printf(R"curr_var %s\n"RS, curr_var->key);
// 			if (strcmp(curr_var->value, cwd) == 0)
// 			{
// 				printf("%s\n", curr_var->value);
// 				return (0);
// 			}
// 			else
// 			{
// 				free(curr_var->value);
// 				curr_var->value = strdup(cwd);
// 				printf("%s\n", curr_var->value);
// 				return (0);
// 			}
// 		}
// 		curr_var = curr_var->next;
// 	}
// 	return (0);
// }
//get our absolute current working directory with getcwd function
//traverse env linked list to find pwd variable
// compare env var if PWD is exist 
//if it exist compare the value with cwd
// if it is the same printf env_var->value,if not
//free curr_var then change or modify the value with cwd



