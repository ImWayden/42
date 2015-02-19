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

size_t	gettickcount()
{
	struct timeval tv;

	if(gettimeofday(&tv, NULL) != 0)
		return 0;
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (!env->start || env->start < gettickcount() + 100)
	{
		env->start = gettickcount();
		env->ptx = (double)x / env->zoom_x + env->x_min;
		env->pty = env->y_max - (double)y / env->zoom_y;
	}
	printf("%u \n", env->start);
	if (button == 4)
	{
		env->z_x += 0.05;
		env->z_y += 0.05;
	}
	else if (button == 5 && env->z_x > 0.001 && env->z_y > 0.001)
	{
		env->z_x -= 0.0005;
		env->z_y -= 0.0005;
	}
	return 0;
}

int		mouse_release(t_env *env)
{
	env->zoom_x *= env->z_x;
	env->zoom_y *= env->z_y;
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
	return (0);
}

int		mouse_hook(int x, int y, t_env *env)
{
	printf("hook %i %i %i %i\n", x, y, env->left, env->right);
	return (0);
}
