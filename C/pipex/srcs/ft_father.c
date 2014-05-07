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

int			ft_father(char **argv, char **str, int fd, int tube[2])
{
	int		tmp;

	tmp = -1;
	str = ft_strsplit(argv[3], ' ');
	close(tube[1]);
	ft_putstr("OK");
	dup2(STDOUT_FILENO, tmp);
	dup2(fd, STDOUT_FILENO);
	dup2(tube[0], STDIN_FILENO);
	execvp(str[0], str);
	close(STDOUT_FILENO);
	dup2(tmp, STDOUT_FILENO);
	ft_putstr(argv[0]);
	ft_putstr(" : ");
	ft_putstr(argv[3]);
	ft_putstr(" : command not found\n");
	exit (0);
}
