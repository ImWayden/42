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

void		julia(t_env *env, int x, int y)
{
	size_t	i;
	t_cplx	 z;
	t_cplx	 a;

	i = -1;
	z.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
	z.i = -(env->pty + ((y - (SCREEN_H / 2)) / env->zoom));
	a = cplx(z.r, z.i);
	while (mod(z) < 4 && ++i < env->max_i)
	{
		a = env->back(env->coeff[i], z.r, z.i);
		z = cplx_add(cplx_pow(z, env->pow), env->c);
	}
	plotpixel(env, x, y, get_color(env, z, a, i));
}