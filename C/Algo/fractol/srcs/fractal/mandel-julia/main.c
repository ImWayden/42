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
	float	tmp;
	float	tmp2;
	t_rgb	color;
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
		//a = sqrt(env->z.i);
		//env->dist = 2.0 * a * log(a) / sqrt(tmp2);
		
		env->dist = MIN(env->dist, abs(dot(env->z, env->z) - RANDR(0.0, 0.0)));
	}
	env->i = i;
	if (i != env->max_i)
	{
		curl(env, env->z.r, env->z.i);
		return rgb(env->z.r * 255, env->z.i * 255, i * 255);
	}
	else if (abs(env->z.r - sin(env->z.i * 1000) / 9) < 0.02)
		color = rgb(0, (sin(env->z.r * 400.0) + 1) / 2 * 255, 0);
	else if (abs(env->z.i - sin(env->z.r * 180)) < 0.02)
		color = rgb((sin(env->z.i * 400) + 1) / 2 *255, 0, 0);
	else //(tmp2 > 4.0)
		color = rgb(0,0,0);
	return linear_inter(env->rgbmap[i % 3], color, env->z.i);
}

int			main_mandel(t_env *env)
{
	int     x;
	int     y;
	//int     i;
	t_rgb	color;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			env->conf ? julia(env, x, y) : mendel(env, x, y);
			color = iterator(env);
		//	printf("%lf %lf\n", env->c.r, env->c.i);
			//color = basecolor(env);
			plotpixel(env, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}