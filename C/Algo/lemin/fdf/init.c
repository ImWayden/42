/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 16:54:09 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 22:52:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_get_tab(t_coord **tab, int k)
{
	int			j;
	int			i;

	i = 0;
	while (i < k)
	{
		ft_putnbr(i);
		j = 0;
		tab[i] = (t_coord *)malloc(sizeof(t_coord) * (k + 1));
		tab[i][k].z = -2;
		while (tab[i][j].z != -2)
		{
			tab[i][j].x = j;
			tab[i][j].y = i;
			tab[i][j].z = 0;
			j++;
		}
		i++;
	}
	return (k);
}

int				init(t_env *env, t_coord coord)
{
	int			i;
	int			j;
	int			pad;
	t_coord		**tab;

	i =  coord.x + 2;
	j =  coord.y + 2;
	if ((tab = (t_coord **)malloc(sizeof(t_coord *) * (i + 1))))
	{
		tab[i] = NULL;
		ft_get_tab(tab, j);
		if (j < 100)
			pad = 20;
		else
			pad = 5;
		env->x = j;
		env->y = i;
		env->pad = pad;
		i = i * 5;
		transform(tab, pad, j * pad, i);
		env->tab = tab;
	}
	return (0);
}
