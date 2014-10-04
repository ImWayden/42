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

	dir = NULL;
	if ((dir = ft_parse(--argc, ++argv)))
	{
		if (!dir->dir && !dir->error)
			ft_ls(".", dir);
		while (dir->dir)
		{
			if (dir->error || dir->dir->next)
			{
				ft_putstr(dir->dir->str);
				ft_putstr(":\n");
			}
			if (!stat(dir->dir->str, &test) && (S_ISDIR(test.st_mode)))
				ft_ls(dir->dir->str, dir);
			else if (!stat(dir->dir->str, &test))
				ft_putdir(dir->dir->str, dir, test);
			if ((dir->dir = ft_delelmt(dir->dir)))
				ft_putendl(NULL);
			dir->error = 1;
		}
	}
	return (0);
}
