/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 20:22:15 by msarr             #+#    #+#             */
/*   Updated: 2015/03/13 20:22:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	addred(t_env *env, t_cplx *z, int n)
{
	int		x;
	int		y;
	int		i;

	i = -1;
	while (++i < env->max_i)
	{
		x = (z[i].r - env->x_min) * env->zoom_x;
		y = -((z[i].i - env->y_max) * env->zoom_y);
		if (x > 0 && y > 0 && x < env->xres && y < env->yres)
		{
			if (n < 115)
				env->pixels[x][y].r++;
			if (n < 30)
				env->pixels[x][y].g++;
			if (n < 20)
				env->pixels[x][y].b++;
		}
	}
}

void		*buddha(void *ptr)
{
	t_env	*env;
	int		x;
	int		y;
	int		i;
	t_cplx	 z;
	t_cplx	 zt[ITT];
	t_cplx	 c;
	t_cplx	 a;

	getarg(ptr, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		i = -1;
		while (++i < env->max_i)
			zt[i] = cplx(0.0, 0.0);
		c.r = (double)x / env->zoom_x + env->x_min;
		c.i = env->y_max - (double)y / env->zoom_y;
		a = cplx(c.r, c.i);
		z = cplx(0.0, 0.0);
		i = -1;
		while (mod(z) < 4 && ++i < env->max_i)
		{
			z = cplx_add(cplx_mult(z, z), c);
			a = curl(env->coeff[i % env->nc], a.r, a.i);
			zt[i] = cplx(z.r, z.i);
		}
		plotpixel(env, x, y, lerp(c, arg(c)));
		if (i < env->max_i)
			addred(env, zt, i);
	}
	return (NULL);
}