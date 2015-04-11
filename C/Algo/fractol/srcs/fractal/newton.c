/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:21:49 by msarr             #+#    #+#             */
/*   Updated: 2015/04/11 16:21:52 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		newton_color(t_env *env, t_cplx z, t_cplx a, size_t i)
{
	t_rgb	r;

	if (i == env->max_i)
	{
		a = env->back(env->coeff[i % NCOEFF], a.r, a.i);
		r = getcolor(a);
	}
	else
	{
		a = env->back(env->coeff[i % NCOEFF], z.r, z.i);
		r = style2(a, env->color[i % NCOLORS], i);
	}
	return (r);
}

void		*newton(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	t_cplx	c1;
	t_cplx	c2;
	t_cplx	c3;
	t_cplx	 z;
	size_t	i;
	double	max_mod;

	c1 = cplx(1, 0);
	c2 = cplx(-0.5, sin(2 * M_PI / 3));
	c3 = cplx(-0.5, -sin(2 * M_PI / 3));
	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		i = -1;
		max_mod = 0.0;
		z.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		z.i = -(env->pty + ((y - (SCREEN_H / 2)) / env->zoom));
		while (mod(cplx_sub(z, c1)) > EPS && mod(cplx_sub(z, c2)) > EPS
				&& mod(cplx_sub(z, c3)) > EPS && ++i < env->max_i)
		{
			if (mod(z) > 0)
			{
				z = cplx_sub(z, cplx_sub(cplx_mult(cplx_mult(z, z), z), cplx(1.0, 0)));
				z = cplx_div(z, cplx_mult2(cplx_mult(z, z), 3.0));
			}
			if (mod(z) > max_mod)
				max_mod = mod(z);
		}
		if (mod(cplx_sub(z, c1)) <= EPS)
			plotpixel(env, x, y, Red);
		if (mod(cplx_sub(z, c2)) <= EPS)
			plotpixel(env, x, y, Blue);
		if (mod(cplx_sub(z, c2)) <= EPS)
			plotpixel(env, x, y, Green);
	}
	pthread_exit(NULL);
	return (NULL);
}