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

int			ft_father(char **argv, int fd, int tube[2])
{
	int		tmp;
	char	**str;

	tmp = -1;
	if ((str = ft_strsplit(argv[3], ' ')))
	{
		close(tube[1]);
		dup2(STDOUT_FILENO, tmp);
		dup2(tube[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		execvp(str[0], str);
		close(fd);
		perror(ft_strjoin("ft_pipex[ft_father] : ", argv[3]));
		exit (0);
	}
	else
		exit (0);
}
