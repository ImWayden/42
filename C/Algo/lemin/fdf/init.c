/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 16:54:09 by msarr             #+#    #+#             */
/*   Updated: 2014/12/10 19:17:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void		padding(t_env *env, t_lem * lem)
{
	int 		i;

	i = 0;
	while (i < 1000)
	{
		if (lem->tab[i])
		{
			if (lem->tab[i]->x > env->max_x)
				env->max_x = lem->tab[i]->x;
			if (lem->tab[i]->x < env->min_x)
				env->min_x = lem->tab[i]->x;
			if (lem->tab[i]->y > env->max_y)
				env->max_y = lem->tab[i]->y;
			if (lem->tab[i]->y < env->min_y)
				env->min_y = lem->tab[i]->y;
		}
		i++;
	}
	env->max_x -= env->min_x;
	env->max_y -= env->min_y;
	env->pad = 1;
	while (env->pad * (env->max_x + 2) < 1500 && env->pad
					* (env->max_y + 1) < 750 /*&& env->pad < 40*/)
		env->pad++;
	env->pad--;
}

static void		trans(t_env *env, t_lem *lem)
{
	int 		i;

	i = 0;
	while (i < 1000)
	{
		if (lem->tab[i])
		{
			lem->tab[i]->x = (lem->tab[i]->x - env->min_x + 1) * env->pad;
			lem->tab[i]->y = (lem->tab[i]->y - env->min_y + 1) * env->pad;
		}
		i++;
	}
}


int				init(t_env *env, t_lem *lem)
{
	env->max_x = lem->start->x;
	env->min_x = lem->start->x;
	env->max_y = lem->start->y;
	env->min_y = lem->start->y;
	env->lem = lem;
	env->room = lem->tab;
	project(env->room);
	padding(env, lem);
	trans(env, lem);
	env->w = (env->max_x + 2) * env->pad;
	env->h = (env->max_y + 2) * env->pad;
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