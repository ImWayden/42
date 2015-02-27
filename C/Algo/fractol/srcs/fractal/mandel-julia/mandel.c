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

t_rgb		mandel_iter(t_env *env, int x, int y)
{
	int		i;
	t_cplx	 z;
	t_cplx	 c;

	i = 0;
	c.r = (double)x / env->zoom_x + env->x_min;
	c.i = env->y_max - (double)y / env->zoom_y;
	z.r = 0;
	z.i = 0;
	while (mod(z) < 4 && i < env->max_i)
	{
		z = cplx_add(cplx_mult(z, z), c);
		i++;
	}
	if (i == env->max_i)
		return (Black);
	return (lerp(heart(env->colormap[i % 3], x, y), i));
}
