/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:27:39 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 22:27:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		ft_open(char *str)
{
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("map missing or open problem !");
		exit (0);
	}
	return (fd);
}

static int		ft_malloc(int ***tab)
{
	*tab = (int **)malloc(sizeof(int *) * 24);
	if (!tab)
	{
		ft_putendl("malloc eror!");
		exit (0);
	}
	return (0);
}

static int		ft_getfile(int fd, int **tab)
{
	int			i;
	int			j;
	char		*s;
	char		*tmp;

	i = 0;
	while (get_next_line(fd, &s) && i < 24)
	{
		j = 0;
		tmp = s;
		tab[i] = (int *)malloc(sizeof(int) * 24);
		while (j < 24)
		{
			if (ft_isdigit(*tmp))
			{
				tab[i][j] = *tmp - 48;
				j++;
			}
			tmp++;
		}
		ft_memdel((void **)&s);
		i++;
	}
	return (0);
}

int				get_map(int ***tab, char *file)
{
	int			fd;

	fd = ft_open(file);
	ft_malloc(tab);
	ft_getfile(fd, *tab);
	return (0);
}
