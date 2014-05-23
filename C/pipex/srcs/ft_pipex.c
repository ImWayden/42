/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 03:00:29 by msarr             #+#    #+#             */
/*   Updated: 2013/12/31 03:00:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int				main(int argc, char **argv)
{
	pid_t		father;
	int			tube[2];
	int			fd;

	pipe(tube);
	fd = -1;
	father = fork();
	if (argc == 5)
	{
		if (father > 0)
		{
			wait(NULL);
			ft_father(argv, fd, tube);
		}
		if (father == 0)
			ft_son(argv, fd, tube);
	}
	return (0);
}
