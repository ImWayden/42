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

static void	project(t_env *env, t_rgb rgb, t_cplx z)
{
	double	theta2;
	double	x;
	double	y;

	theta2 = 2.0 * M_PI;
	x = (z.r * cos (theta2) - z.i * sin(theta2));
	y = z.r * sin(theta2) + z.i * cos(theta2);
	theta2++;
	if (x >= env->x_min && x <= env->x_max)
	{
		if (y >= env->y_min && y <= env->y_max)
		{
			x = env->xres - (((env->x_max - x) / env->ranx) * env->xres);
			y = env->yres - (((env->y_max - y) / env->rany) * env->yres);
			if (x >= 0 && x < env->xres && y >= 0 && y < env->yres)
			{
				if (ISBLACK(getpixel(env, x, y)))
					plotpixel(env, (int)x, (int)y, basecolor(z, rgb));
				else
					addpixel(env, (int)x, (int)y, basecolor(z, rgb));
			}
		}
	}
}

void		flame(t_env *env, int x, int y)
{
	double	x1;
	double	y1;
	t_coeff	c;
	int		step;
	t_cplx	z;
	int		i;

	z.r = (double)x / env->zoom_x + env->x_min;
	z.i = env->y_max - (double)y / env->zoom_y;
	step = -20;
	while (step < env->max_i)
	{
		i = random() % env->nc;
		c = env->coeff[i];
		x1 = c.ac * z.r + c.bc * z.i + c.cc;
		y1 = c.dc * z.r + c.ec * z.i + c.fc;
		z = curl(c, x1, y1);
		if (step > 0)
			project(env, env->rgbmap[i], z);
		step++;
		x1++;
		y1++;
	}
}
