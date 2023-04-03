#include "../../headers/minishell.h"

int	export(t_cmd *cmd, t_envnode *env_var)
{
	char	*var_name;
	char	*var_value;
	int		len;
	int		i;
	int		j;

	//  if (argc < 2) {
    //     printf("Usage: export VAR=value\n");
    //     return 1;
    // }
	var_name = strdup(env_var->key);
	var_value = strdup(env_var->value);
	len = ft_strlen(cmd->cmd_args->args);
	i = 0;
	j = 0;
	while (i < len && cmd->cmd_args->args[i] != '=' )
	{
		if (ft_strcmp(&cmd->cmd_args->args[0], "export") == 0)
			var_name[i] = cmd->cmd_args->args[i];
		i++;
	}
	var_name[i] = '\0';
	if (i == len)
	{
		printf("Usage: export VAR=value\n");
		return(1);
	}
	while (i < cmd->cmd_args->args[i])
	{
		if (ft_strcmp(&cmd->cmd_args->args[0], "export") == 0)
			var_value[j] = cmd->cmd_args->args[i];
		i++;
		j++;
	}
	var_value[j] = '\0';
	//-----setenv----
	ft_setenv(var_name, var_value, &env_var);
	printf("%s=%s", var_name, var_value);
	free(var_name);
	free(var_value);
	return (0);
}
