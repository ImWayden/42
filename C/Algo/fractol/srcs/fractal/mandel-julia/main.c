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

void		*mandelbrot(void *arg)
{
	t_env	*env;
	int     x;
	int     y;
	t_rgb	color;

	y = ((t_thread *)arg)->y_min;
	env = ((t_thread *)arg)->env;
	while (y < ((t_thread *)arg)->y_max)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			color = env->conf ? julia_iter(env, x, y) : mandel_iter(env, x, y) ;
			plotpixel(env, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}
