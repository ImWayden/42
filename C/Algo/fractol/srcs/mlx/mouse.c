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
	if (keycode == 65307)
		ft_exit(env, "See ya.");
	if (keycode == '=' || keycode == 65451)
		env->max_i += 10;
	if (keycode == '-' || keycode == 65453)
		env->max_i -= 10;
	env->max_i = env->max_i < 0 ? 0 : env->max_i;
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 5  || button == 4)
	{
		gettimeofday(&(env->end), NULL);
		if ((env->end.tv_sec - env->start.tv_sec) > 1)
		{
			env->ptx = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
			env->pty = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		}
		if (button == 4)
			env->zoom *= ZOOM_FACTOR;
		if (button == 5)
			env->zoom /= ZOOM_FACTOR;
		env->max_i = (env->zoom)* 0.049715909 * log10(SCREEN_W) ;
		printf("%li\n", env->max_i);
		render(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
		
		gettimeofday(&(env->start), NULL);
	}
	return 0;
}

int		mouse_motion(int x, int y, t_env *env)
{
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
