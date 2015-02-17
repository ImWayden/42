/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 21:49:32 by msarr             #+#    #+#             */
/*   Updated: 2015/01/25 21:49:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		iterator(t_env *env)
{
	int		i;
	double	tmp;
	double	tmp2;
	//t_rgb	color;
	//double	a;

	i = 0;
	tmp2 = 0;
	env->dist = 10000.0;
	while ((tmp2) < 4 && i < env->max_i)
	{
		tmp = env->z.r * env->z.r - env->z.i * env->z.i + env->c.r;
		env->z.i = 2 * env->z.r * env->z.i + env->c.i;
		env->z.r = tmp;
		i++;
		tmp2 = env->z.r * env->z.r + env->z.i * env->z.i;
		env->dist = MIN(env->dist, abs(dot(env->z, env->z) - RANDR(0.0, 0.0)));
	}
	if (i == env->max_i)
		return (Black);
	return (env->rgbmap[i % 3]);
}

int			main_mandel(t_env *env)
{
	int     x;
	int     y;
	t_rgb	color;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			env->conf ? julia(env, x, y) : mendel(env, x, y);
			color = iterator(env);
			plotpixel(env, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}