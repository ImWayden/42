/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 16:54:09 by msarr             #+#    #+#             */
/*   Updated: 2014/12/03 15:42:45 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord			new_coord(float x, float y)
{
	t_coord		new;

	new.x = x;
	new.y = y;
	return (new);
}


int			init(t_env *env, t_lem *lem)
{
	env->pad = 24;
	env->x = 24;
	env->y =  24;
	env->w = env->x++ * env->pad * 2;
	env->h = env->y++ * env->pad * 2;
	env->room = lem->tab;
	project(env, env->room);
	if ((env->ptr = mlx_init()) == NULL)
		exit (0);
	if (!(env->win = mlx_new_window(env->ptr, env->w, env->h, "fdf")))
		exit (0);
	return (1);
}