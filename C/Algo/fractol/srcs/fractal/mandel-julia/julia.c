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

t_rgb		julia_iter(t_env *env, int x, int y)
{
	int		i;
	double	tmp;
	double	tmp2;
	t_cplx	 z;
	t_cplx	 c;

	i = 0;
	tmp2 = 0;
	z.r = (double)x / env->zoom_x + env->x_min;
	z.i = env->y_max - (double)y / env->zoom_y;
	c = conf(env->conf);
	while ((tmp2) < 4 && i < env->max_i)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp;
		i++;
		tmp2 = z.r * z.r + z.i * z.i;
	}
	if (i == env->max_i)
		return (Black);
	return (env->rgbmap[i % 3]);
}