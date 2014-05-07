/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_son.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 06:18:41 by msarr             #+#    #+#             */
/*   Updated: 2013/12/31 06:18:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int			ft_son(char **argv, char **str, int fd, int tube[2])
{
	int		tmp;

	tmp = -1;
	str = ft_strsplit(argv[2], ' ');
	close(tube[0]);
	fd = open(argv[1], O_WRONLY);
	if (fd < 0)
	{
		write (1, argv[1], ft_strlen(argv[1]));
		write (1, ": No such file or directory\n", 28);
	}
	else
		close(fd);
	dup2(STDOUT_FILENO, tmp);
	dup2(tube[1], STDOUT_FILENO);
	execvp(str[0], str);
	dup2(tmp, STDOUT_FILENO);
	ft_putstr(argv[0]);
	ft_putstr(" : ");
	ft_putstr(str[0]);
	ft_putstr(" : command not found\n");
	exit(0);
}
