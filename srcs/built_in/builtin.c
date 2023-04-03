#include"../../headers/minishell.h"

char *builtins(char *cmd)
{
	char *commands = cmd;
    int builtin;

	t_pipeline builtins[] = {
    {"pwd", 3, PWD},
    {"cd", 2, CD},
	{"echo", 4, CMD_ECHO},
    {"unset", 5, UNSET},
    {"export", 6, EXPORT},
	{"env", 3, ENV},
	{"exit", 4, EXIT}
	};
	
	// commands = builtins;
    // t_envnode   *env = NULL;

}

 static int    is_builtin_type(char *content)
 {
	if (ft_strncmp(content, "echo", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "cd", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "pwd", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "env", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "export", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "unset", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "exit", ft_strlen(content)))
		return (1);
	return (0);
 }

char	ft_cmp(char *commands, char *arg)
{
	t_envnode	*env_list;
	t_token		*head;
	// t_cmd	num_args;

	head = NULL;
	env_list = NULL;
	// parse(head);

	while (head)
	{
		if (ft_strcmp(arg[0], is_builtin_type(commands)) == 0)
		{
			
			
		}
	}
	


}
 