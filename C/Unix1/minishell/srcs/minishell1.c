/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:30:21 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:30:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static char		*ft_access(char **path, char *cmd)
{
	char		*str;
	struct stat	tmp;
	int			i;

	i = 0;
	if (cmd && *cmd == '/')
	{
		if (!stat(cmd, &tmp))
			return (cmd);
		else
			return (NULL);
	}
	while (path && path[i])
	{
		str = ft_strjoin(ft_strjoin(path[i], "/"), cmd);
		if (!stat(str, &tmp))
			return (str);
		else
			ft_memdel((void **)&str);
		i++;
	}
	return (NULL);
}

static	void	process(char **path, char **cmd, char **envc)
{
	char		*str;
	pid_t		process;

	process = fork();
	if (process > 0)
		wait(NULL);
	if (process == 0)
	{
		if ((str = ft_access(path, cmd[0])))
			execve(str, cmd, envc);
		else
		{
			ft_putstr(cmd[0]);
			ft_putendl(": command not found.");
		}
		exit(0);
	}
	if (process == -1)
		ft_putendl("Fork error : retry !");
}

static void		ft_exec(char *cmd, char ***envc, char **path)
{
	char		**cmd1;

	if ((cmd1 = ft_strsplit(cmd, ' ')) && cmd1[0])
	{
		if (!ft_strcmp(cmd1[0], "env"))
			ft_puttab(*envc);
		else if (!ft_strcmp(cmd1[0], "cd"))
			ft_cd(*envc, cmd1[1]);
		else if (!ft_strcmp(cmd1[0], "unsetenv"))
			*envc = ft_unsetenv(*envc, cmd1[1]);
		else if (!ft_strcmp(cmd1[0], "setenv"))
			*envc = ft_setenv(*envc, cmd1[1]);
		else if (cmd1[0])
			process(path, cmd1, *envc);
	}
}

void			shell(char **env)
{
	char		**path;
	char		*cmd;
	char		**envc;

	if (env && env[0])
	{
		envc = ft_tabdup(env);
		if (!(path = ft_strsplit(ft_getenv(envc, "PATH"), ':')))
			ft_putendl("NO var PATH : You need to give the bin's path.");
		cmd = NULL;
	}
	else
		envc = NULL;
	while (42)
	{
		write(1, "$>", 2);
		get_next_line(0, &cmd);
		cmd = ft_strtrim(cmd);
		if (!ft_strcmp(cmd, "exit"))
			exit (1);
		if (envc)
			ft_exec(cmd, &envc, path);
		ft_memdel((void **)&cmd);
	}
}
