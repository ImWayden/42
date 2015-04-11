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


int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_exit(env, "See ya.");
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 5  || button == 4)
	{
		gettimeofday(&(env->end), NULL);
		if ((env->end.tv_usec - env->start.tv_usec) > 75000)
		{
			env->ptx = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
			env->pty = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		}
		if (button == 4)
			env->zoom *= ZOOM_FACTOR;
		if (button == 5)
			env->zoom /= ZOOM_FACTOR;
		env->max_i = (SCREEN_W / 2) * 0.049715909 * log10(env->zoom);
		gettimeofday(&(env->start), NULL);
		render(env);
		mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	}
	return 0;
}

int		mouse_motion(int x, int y, t_env *env)
{
	if (env->fract == julia)
	{
		env->c.i -= 0.05;
		if (env->c.i < -1)
		{
			env->c.i = 1;
			env->c.r -= 0.05;
		}
		if (env->c.r < -1)
			env->c.r = 1;
		
		render(env);
		mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	}
	(void)x;
	(void)y;
	(void)env;
	return (0);
}

int		loop_hook(t_env *env)
{
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}
