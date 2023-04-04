#include "../../headers/minishell.h"

void execute(t_cmd *cmd, t_envnode *mini_env) //t_pipeline *pipeline
{
	char	**arg_cmds = NULL;
	printf(R "EXECUTE: " RS);
	print_cmd(cmd);
	arg_cmds = create_array(&cmd);
	printf("argcmd_exc %s\n", *arg_cmds);
	if (is_builtin(arg_cmds, mini_env) == -1)
		printf("NOT builtin\n");
	
	
	// printf("arg_cmds %s\n", *arg_cmds);

	
	// print_pipeline(pipeline);
	// if (cmd && cmd->cmd_args && cmd->cmd_args->file)
	// {
	// 	while (cmd->cmd_args->next)
	// 	{
	// 		printf(GREEN "%s\n", cmd->cmd_args->next->file);
	// 		cmd->cmd_args->next = cmd->cmd_args->next->next;
	// 	}
		
	// }
}


