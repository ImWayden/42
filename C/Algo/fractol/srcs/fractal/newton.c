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
	t_cplx	c[3];
	t_cplx	 z;
	t_cplx	 zn;
	t_cplx	 zd;
	size_t	i;
	int		j;

	i = -1;
	while (++i < 3)
		c[i] = cplx(cos(2 * i * M_PI / 3), sin(2 * i * M_PI / 3));
	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		i = -1;
		z.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		z.i = (env->pty + ((y - (SCREEN_H / 2)) / env->zoom));
		while (cplx_abs(cplx_sub(z, c[0])) > EPS && cplx_abs(cplx_sub(z, c[1])) > EPS
				&& cplx_abs(cplx_sub(z, c[2])) > EPS && ++i < env->max_i)
		{
			if (cplx_abs(z) > 0)
			{
				zn = cplx_add(cplx_mult(cplx(2.0, 0.0), cplx_pow(z, 3)), cplx(1.0, 0));
				zd = cplx_mult(cplx(3, 0), cplx_pow(z, 2));
				z = cplx_div(zn, zd);
			}
		}
		j = -1;
		while (++j < 3)
			if (cplx_abs(cplx_sub(z, c[j])) <= EPS)
				plotpixel(env, x, y, env->color[j]);
	}
	pthread_exit(NULL);
	return (NULL);
}