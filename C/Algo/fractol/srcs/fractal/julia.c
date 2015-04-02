/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 19:09:17 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 19:09:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*julia(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	int		i;
	t_cplx	 z;
	t_cplx	 c;
	t_cplx	 a;

	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		i = -1;
		z.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		z.i = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		c.r = 0.285;
		c.i = 0.013;
		a = cplx(z.r, z.i);
		while (mod(z) < 4 && ++i < env->max_i)
			z = cplx_add(cplx_mult(z, z), c);
		a = cross(env->coeff[i % NCOEFF], z.r, z.i);
		if (i == env->max_i)
			plotpixel(env, x, y, getcolor(z));
		else
			plotpixel(env, x, y, lerp(a, i));
	}
	return (NULL);
}