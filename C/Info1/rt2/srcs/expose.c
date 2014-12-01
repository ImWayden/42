/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 01:13:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 11:36:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void PlotPixel(t_env *env, int x, int y, t_vect color)
{

	unsigned int p = x + y* SCREEN_W;
	//"plot" the pixel
	p*=4;
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

	cam_setup(&env->cam);
	x = 0;
	while (x < SCREEN_W)
	{
		y = 0;
		while (y < SCREEN_H)
		{
			ray = pixel(&env->cam, x, y);
			color = raytrace(&ray, env);
			PlotPixel(env, x, y, color);
			y++;
			(void)color;
		}
		x++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (1);
}