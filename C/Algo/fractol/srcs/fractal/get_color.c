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

	if (i == env->max_i)
	{
		a = env->back(env->coeff[1], a.r, a.i);
		r = getcolor(a);
	}
	else
	{
		a = env->back(env->coeff[1], z.r, z.i);
		r = style2(a, env->color[1], i);
	}
	return (r);
}