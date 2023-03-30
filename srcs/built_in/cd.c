#include"../../headers/minishell.h"

int	ft_cd(t_cmd *cmd, t_envnode *env_list)
{
	char	*path;
	t_envnode	*pwd;
	
	if (cmd->cmd_args->args[1] == 0)
	{
		env_list = find_env_var("HOME", env_list);
		if (ft_strlen(env_list->value) != 0)
			path = env_list->value;
		else
		{
			printf("HOME is not being set \n");
			return (1);
		}
	}
	else
		path = &cmd->cmd_args->args[1];
	// update_env_var("PWD", path);
	// Change the current working directory and update PWD variable
	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
			printf("bash: cd: %s: No such file or directory\n", path);
		else
			printf("bash: cd: %s: Not a directory\n", path);
	}
	else
	{
		pwd = find_env_var("PWD", env_list);
        if (pwd)
		{
            free(pwd->value);
            pwd->value = getcwd(NULL, 0);
        } 
		else
            ft_setenv("PWD", getcwd(NULL, 0), env_list);
        return 0;
	}
	return (0);
}

// int	check_built_in(char **arg)
// {
// 	if (strcmp(arg[0], "cd\n" == 0)
// 		|| strcmp(arg[0], "pwd\n" == 0)
// 		|| strcmp(arg[0], "echo\n" == 0)
// 		|| strcmp(arg[0], "export\n" == 0)
// 		|| strcmp(arg[0], "unset\n" == 0)
// 		|| strcmp(arg[0], "env\n" == 0)
// 		|| strcmp(arg[0], "exit\n" == 0))
// 		return (0);
// 	else
// 	{
// 		perror("command not found");
// 		return(1);
// 	}
// }
// void	go_to_directory(t_token *path, t_envn **env)
// {
// 	char	*old_pwd;
// 	char	*new_pwd;
// 	int		has_access;

// 	exec_pwd(0, &old_pwd, 0);
// 	has_access = check_access(get_string(path));
// 	if (chdir(get_string(path)) != 0)
// 		cd_print_error(has_access, path);
// 	else
// 		g_status = 0;
// 	if (!old_pwd)
// 		return (error_pwd());
// 	change_old_pwd(env, old_pwd);
// 	exec_pwd(0, &new_pwd, 0);
// 	change_pwd(env, new_pwd);
// 	if (old_pwd)
// 		free(old_pwd);
// 	if (new_pwd)
// 		free(new_pwd);
// }

// void	set_pwd(char *arg, char	*c)
// {
// 	char	*string;

// 	string = ft_strjoin(arg, c);
// 	ms_set_env(g_msh.env, string);
// 	free (string);
// }

// int	ms_cd(char *arg)
// {
// 	char	c[PATH_MAX];

// 	if (arg == NULL)
// 	{
// 		arg = ms_get_env(g_msh.env, "HOME") + 5;
// 		if ((arg - 5) == NULL)
// 		{
// 			printf("cd: HOME not set\n");
// 			return (1);
// 		}
// 	}
// 	getcwd(c, sizeof(c));
// 	if (chdir(arg) == -1)
// 	{
// 		if (arg[0] == '\0')
// 			return (1);
// 		ft_putstr_fd("cd: ", 2);
// 		ft_putstr_fd(arg, 2);
// 		ft_putendl_fd(": No such file or directory", 2);
// 		return (1);
// 	}
// 	set_pwd("OLDPWD=", c);
// 	getcwd(c, sizeof(c));
// 	set_pwd("PWD=", c);
// 	return (0);
// }

// int	b_cd(t_envnode *list, char *input)
// {
// 	if (strcmp(input, "cd") == 0)
// 	{
// 		printf("%s\n", find_env_name(list, "HOME"));
// 	}
// 	else if (strcmp(input, "~") == 0)
// 	{
// 		printf("%s\n", find_env_name(list, "HOME"));
// 	}
// 	// else if (strncmp(input, "cd ..", 5) == 0)
// 	// {
// 	// 	parse_cd(list, input);
// 	// }
// 	else 
// 		printf("Command not found: %s\n", input);
// 	return (0);
// }


// void	cd(t_envnode *curr_var, char *path)
// {
// 	char *norm_path;
// 	char 		*pwd;
// 	size_t		pwd_len;
// 	size_t		path_len;
// 	// char		*old_pwd;
// 	char		*new_dir;

// 	if (path == 0 || path[0] == '~')
// 	{
// 		curr_var = find_env_name(curr_var, "HOME");
// 		if (curr_var == 0)
// 			ft_error("cd: HOME is not set");
// 		//absolute path
// 		norm_path = normalize_path(curr_var->value);
// 	}
// 	else if (path[0] == '/')
// 		norm_path = normalize_path(path);
// 	else
// 	{
// 		//relative path
// 		curr_var = find_env_name(curr_var, "PWD");
// 		if (curr_var == 0)
// 			ft_error("cd: PWD is not set");
// 		pwd = curr_var->value;
// 		pwd_len = strlen(pwd);
// 		path_len = strlen(path);
// 		new_dir = (char *)malloc(sizeof(pwd_len + path_len + 2));
// 		// snprintf(buf, pwd_len + path_len + 2, "%s/%s", pwd, path);
// 		printf("%s %s",pwd, path);
// 		norm_path = normalize_path(new_dir);
// 		free(new_dir);		
// 	}
// 	if (chdir(norm_path) != 0)
// 		ft_error("cd: failed to change directory");
// }
