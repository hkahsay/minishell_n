#include "../headers/minishell.h"

void	prompt(char	*line, t_envnode *my_envp) //t_envnode *my_envp, 
{
	int		fd;
	t_token *head;
	t_cmd	*cmd = NULL;

	head = NULL;
	// cmd = NULL;
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
		head = interp(line);
		// is_builtins(cmd);
		cmd = parse(head);
		printf("value of cmd %s\n", cmd->cmd_args->args);
		// cd(cmd);
		// args = eval_token(head);
		printf("OK head is back\n");
		add_history(line);
		fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		if (strncmp(&cmd->cmd_args->args[0], "cd", 2) == 0)
        	ft_cd(cmd, my_envp);
		// cmd = parse(line, cmd);
	}
	else
		free(line);
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	char	*line;
	t_envnode *my_envp;
	line = NULL;
	my_envp = NULL;
	t_envnode *temp = NULL;

	if (argc != 1 || !argv || !envp)
	{
		printf("Error arguments\n");
		return (-1);
	}
	my_envp = dublicate_env(envp);
	if (!my_envp)
	{
		printf("Failed to create my_environment list\n");
		return (1);
	}
	temp = my_envp;
	print_my_envp(temp);
	while (1)
	{
		prompt(line, my_envp); //my_envp, 
		// mini_pwd2(my_envp);
		// Call cd function
    	
		// cd(my_envp);


	}
	free_myenvp(my_envp);	
	return (0);
}
