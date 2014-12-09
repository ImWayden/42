/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 16:54:09 by msarr             #+#    #+#             */
/*   Updated: 2014/12/07 23:43:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int 			abs(int i)
{
	return (i > 0 ? i : -i);
}

t_coord			new_coord(float x, float y)
{
	t_coord		new;

	new.x = x;
	new.y = y;
	return (new);
}

void		project(t_room **room)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 1000)
	{
		if (room[i] && room[i]->dist < 10000)
		{
			x = room[i]->x;
			y = room[i]->y;
			room[i]->z = room[i]->dist ;
			room[i]->x = 0.71 * (x - y);
			room[i]->y = -0.82 * room[i]->z + 0.41 * (x + y);
		}
		i++;
	}
}


int				init(t_env *env, t_lem *lem)
{
	int			min_x;
	int			min_y;
	int			max_y;
	int			max_x;
	int			i;

	max_x = lem->start->x;
	min_x = lem->start->x;
	max_y = lem->start->y;
	min_y = lem->start->y;
	i = 0;
	env->room = lem->tab;
	project(env->room);
	while (i < 1000)
	{
		if (lem->tab[i])
		{
			if (lem->tab[i]->x > max_x)
				max_x = lem->tab[i]->x;
			if (lem->tab[i]->x < min_x)
				min_x = lem->tab[i]->x;
			if (lem->tab[i]->y > max_y)
				max_y = lem->tab[i]->y;
			if (lem->tab[i]->y < min_y)
				min_y = lem->tab[i]->y;
		}
		i++;
	}
	max_x -= min_x;
	max_y -= min_y;
	env->pad = 1;
	while (env->pad * (max_x + 2) < 750 && env->pad * (max_y + 1) < 600 && env->pad < 40)
		env->pad++;
	env->pad--;
	env->w = (max_x + 2) * env->pad;
	env->h = (max_y + 2) * env->pad;
	i = 0;
	while (i < 1000)
	{
		if (lem->tab[i])
		{
			lem->tab[i]->x = (lem->tab[i]->x + min_x + 1) * env->pad;
			lem->tab[i]->y = (lem->tab[i]->y + min_y + 1) * env->pad;
		}
		i++;
	}
	if ((env->ptr = mlx_init()) == NULL)
		exit (0);
	if (!(env->win = mlx_new_window(env->ptr, env->w, env->h, "fdf")))
		exit (0);
	if (!(env->img = mlx_new_image(env->ptr, env->w, env->h)))
		exit (0);
	if (!(env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sizel
		, &env->endian)))
		exit (0);
	return (1);
}