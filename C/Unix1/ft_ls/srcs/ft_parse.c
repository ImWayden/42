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

static t_dir	*allocdir(void)
{
	t_dir		*dir;

	if ((dir = (t_dir *)malloc(sizeof(t_dir))))
	{
		dir->dir = 0;
		dir->recursive = 0;
		dir->infos = 0;
		dir->sort_type = 0;
		dir->sort_mod = 0;
		dir->hiden = 0;
		dir->dirlist = NULL;
	}
	return (dir);
}

static void		ft_error(char c)
{
	ft_putstr("ft_ls : illegal option -- ");
	ft_putchar(c);
	ft_putendl("usage: ./ft_ls [-Ralrt] [file ...]");
	exit (1);
}

static int		ft_choice(int c, t_dir *dir)
{
	if (c == 'r')
		dir->sort_type = 1;
	else if (c == 'a')
		dir->hiden = 1;
	else if (c == 'R')
		dir->recursive = 1;
	else if (c == 'l')
		dir->infos = 1;
	else if (c == 't')
		dir->sort_mod = 1;
	else
		return (0);
	return (1);
}

t_dir			*ft_parse(int argc, char **argv)
{
	t_dir		*dir;
	int			i;
	char		*str;

	dir = allocdir();
	while (argc && argv && *argv && **argv == '-')
	{
		str = ++(*argv);
		while (*str && (i = ft_choice(*str, dir)))
			str++;
		if (i)
		{
			argv++;
			argc--;
		}
		else
			ft_error(*str);
	}
	if (argc)
		dir->dir = argv;
	return (dir);
}
