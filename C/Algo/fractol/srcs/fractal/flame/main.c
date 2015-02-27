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

static int		get_xy(t_env *env, double *x, double *y, t_cplx z)
{
	int			i;

	i = random () % env->ncolors;	/*RANDR(0,env->ncolor);*/
	*x = env->colormap[i].ac * z.r + env->colormap[i].bc * z.i + env->colormap[i].cc;
	*y = env->colormap[i].dc * z.r + env->colormap[i].ec * z.i + env->colormap[i].fc;
	return (i);
}

static void		project(t_env *env, int i, t_cplx z)
{
	int x1;
	int y1;
	int s;
	double theta2;
	double	x_rot;
	double	y_rot;

	theta2 = 0.0;
	for (s = 0; s < env->symmetry; s++)
	{
		theta2 += (double)((2 * M_PI) / (env->symmetry));
		x_rot = (double)(z.r * cos (theta2) - z.i * sin(theta2));
		y_rot = z.r * sin(theta2) + z.i * cos(theta2);
		if (x_rot >= env->x_min && x_rot <= env->x_max && y_rot >= env->y_min && y_rot <= env->y_max)
		{
			x1 = env->xres - (unsigned int) (((env->x_max - x_rot) / env->ranx) * env->xres);
			y1 = env->yres - (unsigned int) (((env->y_max - y_rot) / env->rany) * env->yres);
			if (x1 >= 0 && x1 < env->xres && y1 >= 0 && y1 < env->yres)
			{
				if (ISBLACK(getpixel(env, x1, y1)))
					plotpixel(env, x1, y1, env->colormap[i % NCOLORS].rgb);
	    		else
					addpixel(env, x1, y1, env->colormap[i % NCOLORS].rgb);
			}
		}
	}
}

void		*flame(void *arg)
{
	double  x, y;
	t_env	*env;
	int i, num;
	long int step;
	t_cplx	z;

	i = 0;
	env = ((t_thread *)arg)->env;
	for (num = 0; num < env->samples / 100; num++)
	{
		z.r = RANDR(env->x_min, env->x_max);
		z.i = RANDR(env->y_min, env->y_max);
		for (step = -20; step < env->max_i; step++)
		{
			i = get_xy(env, &x, &y, z);
			z = cross(env->colormap[i], x, y);
			if (step > 0)
				project(env, i, z);
		}
	}
	return (0);
}