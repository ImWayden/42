/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 06:18:30 by msarr             #+#    #+#             */
/*   Updated: 2013/12/31 06:18:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int		ft_father(char **argv, char **str, int fd, int tube[2])
{
	int		tmp;

	argv[3] = ft_strjoin(ft_strjoin(argv[3], " "), argv[1]);
	str  = ft_strsplit(argv[3], ' ');
	close(tube[1]);
	if (open(argv[1], O_WRONLY) < 0)
		return (0);
	fd = open(argv[4], O_WRONLY);
	if (fd < 0)
	{
		write (1, argv[4], ft_strlen(argv[4]));
		write (1, ": No such file or directory\n", 28);
		return (0);
	}
	dup2(STDOUT_FILENO, tmp);
	dup2(fd, STDOUT_FILENO);
	execvp(str[0], str);
	close(STDOUT_FILENO);
	dup2(tmp, STDOUT_FILENO);
	write (1, argv[0], ft_strlen(argv[0]));
	write (1, " : ", 3);
	write (1, argv[4], ft_strlen(argv[4]));
	write (1, " : command not found\n", 21);
	return (0);
}
