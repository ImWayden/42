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

void		*mandel(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	size_t	i;
	t_cplx	 z;
	t_cplx	 a;
	t_cplx	 c;

	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		c.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		c.i = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		z = cplx(0.0, 0.0);
		a = cplx(c.r, c.i);
		i = -1;
		while (mod(z) < 4 && ++i < env->max_i)
			z = cplx_add(cplx_mult(z, z), c);
		plotpixel(env, x, y, get_color(env, z, a, i));
	}
	pthread_exit(NULL);
	return (NULL);
}
