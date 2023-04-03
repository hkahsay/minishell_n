#include "../headers/minishell.h"

void	prompt(char	*line, t_envnode *my_envp) //t_envnode *my_envp, 
{
	int		fd;
	t_token *head;
	t_cmd	*cmd = NULL;
	char	*built;

	head = NULL;
	// cmd = NULL;
	//       0123
	built = "srcs/built_in";// is_builtin_type(built); //
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
		cmd = parse(head, cmd);
		char buff[1024];
		printf("PWD current directory befor cd: %s\n", getcwd(buff, 1024));
		ft_cd(built, my_envp);
		printf("from cd: %s\n", getcwd(buff, 1024));
		mini_pwd2(my_envp);
		// if (strcmp(cmd->cmd_args->args[0], "echo") == 0)
		// {
		printf("ARGUMENT IN MAIN: %p\n", cmd->cmd_args);
		ft_echo(cmd);
    	// }
		// ft_echo();
		// cd(cmd);
		// args = eval_token(head);
		printf("OK head is back\n");
		add_history(line);
		fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		close(fd);
		// ft_cd(built, my_envp);
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
	print_mini_envp(temp);
	while (1)
	{
		prompt(line, my_envp); //my_envp, 
		// Call cd function
    	// echo(line, my_envp);
		// cd(my_envp);


	}
	free_mini_envp(my_envp);	
	return (0);
}
