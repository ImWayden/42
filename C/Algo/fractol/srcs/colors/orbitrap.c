/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orbitrap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:27:57 by msarr             #+#    #+#             */
/*   Updated: 2015/08/13 14:27:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb			orbitrap(t_env *env, t_cplx z, int i)
{
	double		co;
	double		co2;
	double		fac;

	co = (double)i + 1.0 - log2(0.5 * log2(dot(z,z)));
	co = sqrt(co / 256.0);
	co2 = args(z);
	fac = clamp(1.0/pow(co2,Power),0.0,1.0);
	i = (int)i % NCOLORS ;
	return rgb_mult(rgb_mult(rgb(0.5 + 0.5 * cos(6.2831 * co + env->color[i].r),
			0.5 + 0.5 * cos(6.2831 * co + env->color[i].g),
			0.5 + 0.5 * cos(6.2831 * co + env->color[i].b)), fac), 255.0);
}
