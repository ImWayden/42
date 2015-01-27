/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:06:32 by msarr             #+#    #+#             */
/*   Updated: 2015/01/26 14:06:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_xy(t_env *env, double *x, double *y)
{
	int			i;

	i = random () % env->ncolors;	/*RANDR(0,env->ncolor);*/
	*x = env->colormap[i].ac * env->z.r + env->colormap[i].bc * env->z.i + env->colormap[i].cc;
	*y = env->colormap[i].dc * env->z.r + env->colormap[i].ec * env->z.i + env->colormap[i].fc;
	return (i);
}

static void		project(t_env *env, int i)
{
	int x1;
	int y1;
	int s;
	t_pixel	*point;
	    	unsigned char red, green, blue;
	double theta2, x_rot, y_rot;

	theta2 = 0.0;
	for (s = 0; s < env->symmetry; s++)
	{
		theta2 += (double) ((2 * M_PI) / (env->symmetry));
		x_rot = (double) (env->z.r * cos (theta2) - env->z.i * sin (theta2));
		y_rot = env->z.r * sin (theta2) + env->z.i * cos (theta2);
		if (x_rot >= env->x_min && x_rot <= env->x_max && y_rot >= env->y_min && y_rot <= env->y_max)
		{
			x1 = env->xres - (unsigned int) (((env->x_max - x_rot) / env->ranx) * env->xres);
			y1 = env->yres - (unsigned int) (((env->y_max - y_rot) / env->rany) * env->yres);
			if (x1 >= 0 && x1 < env->xres && y1 >= 0 && y1 < env->yres)
			{
				point = &env->pixels[y1][x1];
				if (!point->value.counter)
				{
					point->r = env->colormap[i].rgb.r;
	    			point->g = env->colormap[i].rgb.g;
	    			point->b = env->colormap[i].rgb.b;
	    		}
	    		else
	    		{
	    			red = (unsigned char) ((point->r + env->colormap[i].rgb.r) / 2);
	    			point->r = red;
	    			green = (unsigned char) ((point->g + env->colormap[i].rgb.g) / 2);
	    			point->g = green;
	    			blue = (unsigned char) ((point->b + env->colormap[i].rgb.b) / 2);
	    			point->b = blue;
	    		}
	    		point->value.counter++;
			}
		}
	}
}

int 			main_flame(t_env *env)
{
	double  x, y;
	int i, num;
	long int step;

	i = 0;
	for (num = 0; num < env->samples; num++)
	{
		env->z.r = RANDR(env->x_min, env->x_max);
		env->z.i = RANDR(env->y_min, env->y_max);
		for (step = -20; step < env->max_i; step++)
		{
			i = get_xy(env, &x, &y);
			linear(env, x, y);
			if (step > 0)
				project(env, i);
		}
	}
	return (0);
}