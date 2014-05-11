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

int			ft_son(char **argv, int fd, int tube[2])
{
	char	**str;

	if ((fd = open(argv[1], O_RDWR)) != -1)
	{
		str = ft_strsplit(argv[2], ' ');
		close(tube[0]);
		dup2(fd, STDIN_FILENO);
		dup2(tube[1], STDOUT_FILENO);
		execvp(str[0], str);
	}
	else
		perror(ft_strjoin("ft_pipex : ", argv[1]));	
	exit(0);
}
