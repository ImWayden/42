/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:16:19 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 22:16:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_env *env)
{
	gettimeofday(&(env->end), NULL);
	if ((env->end.tv_sec - env->start.tv_sec) > 1)
	{
		env->ptx = (double)x / env->zoom_x + env->x_min;
		env->pty = env->y_max - (double)y / env->zoom_y;
	}
	if (button == 5  || button == 4)
	{
		env->z_x += env->zoom_x / 100.0;
		env->z_y += env->zoom_y / 100.0;
	}
	return 0;
}

int		mouse_release(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		env->zoom_x += env->z_x;
		env->zoom_y += env->z_y;
	}
	if (button == 4)
	{
		env->zoom_x -= env->z_x;
		env->zoom_y -= env->z_y;
	}
	env->z_x = 1;
	env->z_y = 1;
	env->ranx = SCREEN_W / env->zoom_x;
	env->rany = SCREEN_H / env->zoom_y;
	env->y_min = env->pty - env->rany / 2.0;
	env->y_max = env->pty + env->rany / 2.0;
	env->x_min = env->ptx - env->ranx / 2.0;
	env->x_max = env->ptx + env->ranx / 2.0;
	env->funct(env);
	expose(env);
	gettimeofday(&(env->start), NULL);
	return (0);
}

int		loop_hook(t_env *env)
{
	(void)env;
	return (0);
}
