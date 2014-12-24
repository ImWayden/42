/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 01:13:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/24 13:43:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void PlotPixel(t_env *env, int x, int y, t_vect color)
{

	unsigned int p = x + y* SCREEN_W;
	//"plot" the pixel
	p*=4;
	color.x = MIN(color.x * 256, 255); 
	color.y = MIN(color.y * 256, 255); 
	color.z = MIN(color.z * 256, 255); 
	env->data[p] = (short)color.x;
	env->data[p + 1] = (short)color.y;
	env->data[p + 2] = (short)color.z;
}

int		expose(t_env *env)
{
	int 	x;
	int		y;
	t_vect	color;
	t_ray	ray;

	y = 0;
	while (y < SCREEN_H)
	{
		x= 0;
		while (x < SCREEN_W)
		{
			ray = pixel(&env->cam, x, y);
			color = raytrace(&ray, env);
			if (color.x || color.y || color.z)
				PlotPixel(env, x, y, color);
			else if (y < SCREEN_H /2)
				PlotPixel(env, x, y, COLOR_BLUE);
			else
				PlotPixel(env, x, y, COLOR_GREEN);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}