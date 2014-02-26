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

#include "my_42sh.h"


void		ft_redir(char **av, char ***envs)
{
	pid_t		father;
	int			fd;
	int			j;
	char		**cmd1;

	cmd1 = ft_strsplit(ft_strtrim(cmd), '>');
	fd = 1;
	father = fork();
	if (father == 0)
	{
		fd = open(ft_strtrim(cmd1[1]), O_RDWR | O_CREAT | O_TRUNC | S_IRWXU);
		dup2(1, j);
		dup2(fd, 1);
		ft_getcmd(cmd1, envs);
		exit (1);
	}
	if (father > 0)
	{
		wait(NULL);
		dup2(j, 1);
		close(fd);
	}	
}
