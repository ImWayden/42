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

static int		isroot(t_cplx z)
{
	t_cplx		z1;

	z1 = cplx_pow(z, 3);
    z1 = cplx_sub(z1, cplx(1, 0));    
    return (fabs(mod(z1)) < EPS);
}

void		newton(t_env *env, int x, int y)
{
	t_cplx	 z;
	t_cplx	 zn;
	t_cplx	 zd;
	t_cplx	 a;
	size_t	i;


	i = -1;
	z.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
	z.i = -(env->pty + ((y - (SCREEN_H / 2)) / env->zoom));
	a = cplx(z.r, z.i);
	while (++i < env->max_i)
	{
		if (mod(z) > 0)
		{
			zn = cplx_sub(cplx_pow(z, env->pow), cplx(1.0, 0));
			zd = cplx_mult(cplx(env->pow, 0), cplx_pow(z, env->pow - 1));
			z = cplx_sub(z, cplx_div(zn, zd));
		}
		if (isroot(z))
			break;
	}
	if (!(isroot(z)))
		plotpixel(env, x, y, Red);//, i));
}
