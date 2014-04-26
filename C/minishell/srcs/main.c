/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 12:47:05 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 12:47:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "minishell2.h"

void	init(char ***path, char ***cmd, char **envc)
{
	char		*str;

	write(1, "$>", 2);
	str = NULL;
	get_next_line(0, &str);
	*path = ft_strsplit(ft_getenv(envc, "PATH"), ':');
	str = ft_strtrim(str);
	*cmd = ft_strsplit(str, ';');
	ft_memdel((void **)&str);
}

static	void	process(char **path, char **cmd, char **envc)
{
	int			i;
	pid_t		process;

	process = fork();
	i = 0;
	if (process > 0)
		wait(NULL);
	if (process == 0)
	{
		while (path[i])
		{
			write(1, "ici", 3);
			ft_putendl(path[i]);
			execve(ft_strjoin(ft_strjoin(path[i], "/"), cmd[0]), cmd, envc);
			i++;
		}
		ft_putendl("command not found");
		exit(1);
	}
	if (process == -1)
		ft_putendl("Fork error : retry !");
}

static	int 	builtin_verif(char *str)
{
	if (ft_strnequ(str, "exit", ft_strlen(str)) == 1)
		return(1);
	if (ft_strnequ(str, "env", ft_strlen(str)) == 1)
		return(2);
	if (ft_strnequ(str, "cd", ft_strlen(str)) == 1)
		return(3);
	if (ft_strnequ(str, "unsetenv", ft_strlen(str)) == 1)
		return(4);
	else
		return (0);
}

static	char	**cp_env(char **env)
{
	int		i;
	char	**envc;

	i = 0;
	envc = (char **)malloc(sizeof(env));
	while (envc && env && env[i])
	{
		envc[i] = ft_strdup(env[i]);
		i++;
	}
	return (envc);
}

int		ft_is(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	shell(char **env)
{
	int			i;
	char		**path;
	char		**cmd;
	char		**envc;

	envc = cp_env(env);
	while (42 && envc)
	{
		init(&path, &cmd, envc);
		i = 0;
		while (cmd && cmd[i])
		{
			ft_exec(cmd[i], envc, path);
			i++;
		}
	}
}

void		ft_exec(char *cmd, char **envc, char **path)
{
	char		**cmd1;

	cmd1 = ft_strsplit(ft_strtrim(cmd), ' ');
	if (cmd1[0] && builtin_verif(cmd1[0]) == 1)
		exit(1);
	else if (cmd1[0] && builtin_verif(cmd1[0]) > 1)
	{
		if (builtin_verif(cmd1[0]) == 2)
					ft_env(envc);
		if (builtin_verif(cmd1[0]) == 3)
					ft_cd(envc, cmd1[1]);
		if (builtin_verif(cmd1[0]) == 4)
					ft_unsetenv(envc, cmd1[1]);
	}
	else if (cmd1[0])
		process(path, cmd1, envc);
}

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		shell(env);
	else
	{
		write(1, argv[0], ft_strlen(argv[0]));
		write(1, " : need to be executed without argument.\n", 41);
	}
	return 0;
}
