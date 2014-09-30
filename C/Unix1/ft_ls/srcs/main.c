/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:22:51 by msarr             #+#    #+#             */
/*   Updated: 2014/04/14 13:22:52 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

int					main(int argc, char **argv)
{
	struct stat		test;
	t_dir			*dir;
	int				i;

	i = 0;
	dir = NULL;
	if ((dir = ft_parse(--argc, ++argv)))
	{
		while (dir->dir && dir->dir[i])
		{
			if (!stat(dir->dir[i], &test) && (S_ISDIR(test.st_mode)))
				ft_ls(dir->dir[i], dir);
			else if (!stat(dir->dir[i], &test))
				ft_putdir(dir->dir[i], dir, test);
			else
				perror(dir->dir[i]);
			i++;
		}
		if (!i)
			ft_ls(".", dir);
	}
	return (0);
}
