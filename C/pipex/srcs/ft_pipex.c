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
	char		**str;
	int			tube[2];
	int			fd;

	pipe(tube);
	str = NULL;
	fd = -1;
	father = fork();
	if (argc == 5)
	{
		if (father > 0)
		{
			wait(NULL);
			fd = open(argv[4], O_WRONLY | O_CREAT);
			if (fd < 0)
				return (0);
			ft_father(argv, str, fd, tube);
			close (fd);
		}
		if (father == 0)
			return (ft_son(argv, str, fd, tube));
	}
	return (0);
}
