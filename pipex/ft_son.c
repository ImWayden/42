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

int		ft_son(char **argv, char **str, int fd, int tube[2])
{
	int		tmp;
	
	str  = ft_strsplit(argv[2], ' ');
	close(tube[0]);
	dup2(STDOUT_FILENO, tmp);
	fd = open(argv[1], O_WRONLY);
	if (fd < 0)
	{
		write (1, argv[1], ft_strlen(argv[1]));
		write (1, ": No such file or directory\n", 28);
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
    execvp(str[0], str);
    close(fd);
    dup2(tmp, STDOUT_FILENO);
    write (1, argv[0], ft_strlen(argv[0]));
	write (1, " : ", 3);
	write (1, str[0], ft_strlen(str[0]));
	write (1, " : command not found\n", 21);
	return (0);	
}
