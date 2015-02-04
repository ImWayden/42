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

int			iterator(t_env *env)
{
	int		i;
	float	tmp;
	float	tmp2;
	//double	a;

	i = 0;
	tmp2 = 0;
	env->dist = 10000.0;
	while ((tmp2) < 4 && i < env->max_i)
	{
		tmp = env->z.r*env->z.r - env->z.i*env->z.i + env->c.r;
		env->z.i = 2*env->z.r*env->z.i + env->c.i;
		env->z.r = tmp;
		i++;
		tmp2 = env->z.r * env->z.r + env->z.i * env->z.i;
		//a = sqrt(env->z.i);
		//env->dist = 2.0 * a * log(a) / sqrt(tmp2);
		env->dist = MIN(env->dist, abs(dot(env->z, env->z) - RANDR(0.0, 2.0)));
	}
	return (i);
}

double		mod(t_cplx a)
{
	return sqrt(a.r * a.r + a.i * a.i);
}

int			main_mandel(t_env *env)
{
	int     x;
	int     y;
	int     i;
	t_rgb	color;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			env->conf == 1 ? julia(env, x, y) : mendel(env, x, y);
			i = iterator(env)
			;//	plotpixel(env, x, y, LightGrey);
			//else
			//{
				//printf("%lf\n", env->dist);
				color = env->colormap[i % NCOLORS].rgb;
				color = style2(env, color, i);
				plotpixel(env, x, y, color);
			//}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}