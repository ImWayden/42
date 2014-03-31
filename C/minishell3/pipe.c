/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 11:21:56 by msarr             #+#    #+#             */
/*   Updated: 2014/01/28 11:21:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"


void		ft_pfp(char **cmd, char **envc, char **path, int *tube)
{
	pid_t		father;

	father = fork();
	if (father > 0)
	{
		wait (NULL);
		close(tube[0]);
	}
	if (father == 0)
	{
		close(tube[1]);
		dup2(tube[0], 0);
		ft_exec(cmd[1], envc, path);
		exit (1);
	}
}

void		ft_pipe(char *cmd, char **envc, char **path)
{
	pid_t		father;
	int			tube[2];
	char		**cmd1;

	cmd1 = ft_strsplit(ft_strtrim(cmd), '|');
	pipe(tube);
	father = fork();
	if (father > 0)
	{
		wait (NULL);
		ft_pfp(cmd1, envc, path, tube);
		//close(tube[0]);
	}
	if (father == 0)
	{
		close(tube[0]);
		dup2(tube[1], 1);
		ft_exec(cmd1[0], envc, path);
		exit (1);
	}
}

void		ft_redir(char *cmd, char **envc, char **path)
{
	pid_t		father;
	int			fd;
	char		**cmd1;

	cmd1 = ft_strsplit(ft_strtrim(cmd), '>');
	father = fork();
	if (father > 0)
	{
		wait(NULL);
		close(fd);
	}
	if (father == 0)
	{
		fd = open(ft_strtrim(cmd1[1]), O_RDWR | O_CREAT | O_TRUNC | S_IRWXU);
		dup2(fd, 1);
		ft_exec(cmd1[0], envc, path);
		exit (1);
	}	
}
