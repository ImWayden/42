/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:52:39 by msarr             #+#    #+#             */
/*   Updated: 2014/04/14 13:52:40 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

t_dir			*ft_parse(int argc, char **argv)
{
	t_dir		*dir;

	dir = (t_dir *)malloc(sizeof(t_dir));
	dir->dir = NULL;
	while (argc && argv && *argv && **argv == '-')
	{
		if (!ft_strcmp("-r", *argv))
			dir->sort_type = 1;
		else if (!ft_strcmp("-a", *argv))
			dir->hiden = 1;
		else if (!ft_strcmp("-R", *argv))
			dir->recursive = 1;
		else if (!ft_strcmp("-l", *argv))
			dir->infos = 1;
		argv++;
		argc--;
	}
	if (argc)
		dir->dir = argv;
	else
		dir->dir = NULL;
	return (dir);
}
