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
		a = env->back(env->coeff[i % NCOEFF], z.r, z.i);
		r = style2(a, env->color[i % NCOLORS], i);
		
	}
	else
	{
		a = env->back(env->coeff[i % NCOEFF], a.r, a.i);
		r = getcolor(a);
	}
	return (r);
}

static int		isroot(t_cplx z)
{
	t_cplx		z1;

	z1 = cplx_pow(z, 3);
    z1 = cplx_sub(z1, cplx(1, 0));    
    return (fabs(mod(z1)) < EPS);
  }

void		*newton(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	t_cplx	 z;
	t_cplx	 zn;
	t_cplx	 zd;
	t_cplx	 a;
	size_t	i;


	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		i = -1;
		z.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		z.i = -(env->pty + ((y - (SCREEN_H / 2)) / env->zoom));
		a = cplx(z.r, z.i);
		while (++i < env->max_i)
		{
			if (cplx_abs(z) > 0)
			{
				zn = cplx_sub(cplx_pow(z, 3), cplx(1.0, 0));
				zd = cplx_mult(cplx(3, 0), cplx_pow(z, 2));
				z = cplx_sub(z, cplx_div(zn, zd));
			}
			if (isroot(z))
				break;
		}
		plotpixel(env, x, y, newton_color(env, z, a, i));
	}
	pthread_exit(NULL);
	return (NULL);
}