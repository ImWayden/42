/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:16:25 by msarr             #+#    #+#             */
/*   Updated: 2015/04/11 13:16:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		get_color(t_env *env, t_cplx z, t_cplx a, size_t i)
{
	t_rgb	r;

	double nsmooth = (i + 1 - log(log(mod(z))) / log(2.0));
	int smoothcolor = (int)nsmooth % NCOLORS;
	if (i == env->max_i)
		return (rgb(0, 0, 0));
	else
		return (env->color[smoothcolor]);
	if (i == env->max_i)
	{
		a = toangle(z);//formula(z);//env->back(env->coeff[i], z.r, z.i);
		r = getcolor(a);
	}
	else
	{
		a = env->back(env->coeff[i], z.r, z.i);
		r = lerp(a);
	}
	return (r);
}