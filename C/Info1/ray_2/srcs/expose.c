/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 01:13:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 17:10:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void plotpixel(t_env *env, int x, int y, t_vect color)
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

t_vect getpixel(t_env *env, int x, int y)
{
	t_vect	color;
	unsigned int p;

	x = x <= 0 ? 0 : x;
	y = y <= 0 ? 0 : y;
	p = x + y * SCREEN_W;
	p*= 4;
	color.x =  env->data[p];
	color.y =  env->data[p + 1];
	color.z =  env->data[p + 2];
	return (color);
}

int		expose(t_env *env)
{
	int 	x;
	int		y;
	t_vect	color;
	t_vect	color1;
	t_ray	ray;
	t_vect 	ph, pg, ch, cg;
	double	diff1, diff2;
	double	j, i,k;
	double	aa;
	int		aa2;
	double	aa_threshold;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			ray = pixel(&env->cam, x, y);
			color = raytrace(&ray, env);
			//PlotPixel(env, x, y, color);
			////////
			////////
			////////
			aa = env->aa;
			aa2 = aa * aa;
			(void)aa2;
			aa_threshold = env->at;
			if (aa > 1)
			{
				if (y == 0 && x == 0)
					ph = pg = new(0.0, 0.0, 0.0);
				if (y == 0 && x > 0)
				{
					ph = new(0.0, x, 0.0);
					pg = new(0.0, x - 1, 0.0);
				}
				if (y > 0 && x == 0)
				{
					ph = new(y - 1, 0.0, 0.0);
					pg = new(y, 0.0, 0.0);
				}
				if (y > 0 && x > 0)
				{
					ph = new(y - 1, x, 0.0);
					pg = new(y, x - 1, 0.0);
				}
				ch = getpixel (env, ph.y, ph.x);
				cg = getpixel (env, pg.y, pg.x);
				diff1 = som(fab(sub(color, ch)));
				diff2 = som(fab(sub(color, cg)));
				k = 1;
				while  (k <= aa && (diff1 > aa_threshold || diff2 > aa_threshold))
				{
					i = ((double) x - (double)rand()/(double)RAND_MAX);
					j = ((double) y - (double)rand()/(double)RAND_MAX);
					j = j < 0 ? 0 : j;
					i = i < 0 ? 0 : i;
					ray = pixel(&env->cam, i, j);
					color1 = raytrace(&ray, env);
					color = divi(add(mult2(color, (aa - 1.0)), color1), (double)aa);
					diff1 = som(fab(sub(color, ch)));
					diff2 = som(fab(sub(color, cg)));
					k++;
				}
			}
			plotpixel(env, x, y, color);
			///////
			///////
			///////
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	//exit (0);
	return (0);
}