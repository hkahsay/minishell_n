#include "../headers/minishell.h"

void	prompt(char	*line, t_envnode *mini_env) //t_envnode *mini_env, 
{
	int		fd;
	// t_token *token_head;
	// t_cmd	*cmd = NULL;
	// char	**arg_cmds;

	// head = NULL;
	// cmd = NULL;
	//       0123
	line = readline ("minishell_VH>> 😜 ");
	// index = getpid();
	if (!line)
	{
		printf("exit\n");
		free(line);
	}
	if (ft_strlen(line) > 0)
	{
		printf("propmt line: %s\n", line);
		interp(line, mini_env);
		printf("OK head is back\n");
		add_history(line);
		fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		close(fd);
		// ft_cd(built, mini_env);
		// cmd = parse(line, cmd);
	}
	else
		free(line);
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	char	*line;
	t_envnode *mini_env;
	line = NULL;
	mini_env = NULL;
	t_envnode *temp = NULL;

	if (argc != 1 || !argv || !envp)
	{
		printf("Error arguments\n");
		return (-1);
	}
	mini_env = duplicate_env(envp);
	if (!mini_env)
	{
		printf("Failed to create my_environment list\n");
		return (1);
	}
	temp = mini_env;
	print_mini_envp(temp);
	while (1)
	{
		prompt(line, mini_env); //mini_env, 
		// Call cd function
    	// echo(line, mini_env);
		// cd(mini_env);


	}
	free_mini_envp(mini_env);	
	return (0);
}
