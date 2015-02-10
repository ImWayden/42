/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:45:12 by msarr             #+#    #+#             */
/*   Updated: 2015/02/02 13:45:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Imprecise method which does not guarantee v = v1 when t = 1,
// due to floating-point arithmetic error.
t_rgb		linear_inter(t_rgb v0, t_rgb v1, double t)
{
	return (rgb_add(v0, rgb_mult(rgb_sub(v1, v0), t)));
}
 
// Precise method which guarantees v = v1 when t =
t_rgb		lerp(t_env *env, double t)
{
	t_rgb 	r;
	double		p1;

	r = rgb(env->z.r, env->z.i, t);
	p1 = sqrt (r.r * r.r + r.g * r.b);
	p1++;
	r.r = sqrt(2.0 / (p1 + 1)) * env->z.r * 255;
	r.g = sqrt(2.0 / (p1 + 1)) * env->z.i * 255;
	r.b = (int)(t * 255) % 256;
	return r;
}