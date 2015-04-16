/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 15:19:03 by msarr             #+#    #+#             */
/*   Updated: 2015/04/14 15:19:06 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*burningship(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	size_t	i;
	t_cplx	 z;
	t_cplx	 c;
	t_cplx	 a;

	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		c.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		c.i = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		z = cplx(0.0, 0.0);
		a = cplx(c.r, c.i);
		i = -1;
		while (++i < env->max_i && cplx_abs(z) < 2)
		{
			z = cplx(fabs(z.r), fabs(z.i));
			z = cplx_add(cplx_mult(z, z), c);
		}
		plotpixel(env, x, y, get_color(env, z, a, i));
	}
	pthread_exit(NULL);
	return (NULL);
}

