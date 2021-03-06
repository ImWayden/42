/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:03:34 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 15:03:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel(t_env *env, int x, int y)
{
	size_t	i;
	t_cplx	z;
	t_cplx	a;
	t_cplx	c;

	c.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
	c.i = (env->pty + ((y - (SCREEN_H / 2)) / env->zoom));
	z = cplx(0.0, 0.0);
	a = cplx(c.r, c.i);
	i = -1;
	while (mod(z) < 4 && ++i < env->max_i)
	{
		a = env->back(env->coeff[1], z.r, z.i);

		//z = cplx_add(cplx_pow(z, env->pow), c);
	}
			//a = env->back(env->coeff[1], a.r, a.i);
	
	plotpixel(env, x, y, get_color(env, a, a, i));
}
