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


int				init(t_env *env, t_lem *lem)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 1000)
	{
		if (lem->tab[i])
		{
			if (abs(lem->tab[i]->x) > x)
				x = abs(lem->tab[i]->x);
			if (abs(lem->tab[i]->y) > y)
				y = abs(lem->tab[i]->y);
		}
		i++;
	}
	printf("%i : y ; %i : x\n", y , x);
	env->pad = 50;
	while (env->pad * (x + 1) > 750 || env->pad * (y + 1) > 600)
		env->pad--;
	printf("%i : pad\n", env->pad);
	env->w = (x + 1) * 2 * env->pad;
	env->h = (y + 1) * 2 * env->pad;
	env->x = env->w / 2;
	env->y = env->h / 2;
	env->room = lem->tab;
	project(env, env->room);
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