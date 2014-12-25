/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 01:13:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 16:57:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void PlotPixel(t_env *env, int x, int y, t_vect color)
{

	unsigned int p = x + y* SCREEN_W;
	//"plot" the pixel
	p*=4;
	color.x = MAX(0, MIN(color.x * 256, 255)); 
	color.y = MAX(0, MIN(color.y * 256, 255)); 
	color.z = MAX(0, MIN(color.z * 256, 255)); 
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
			PlotPixel(env, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	//exit (0);
	return (0);
}