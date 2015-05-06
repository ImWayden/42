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

t_rgb		linear_inter(t_rgb v0, t_rgb v1, double t)
{
	return (rgb_add(v0, rgb_mult(rgb_sub(v1, v0), t)));
}

t_rgb		lerp(t_cplx z)
{
	t_rgb 	r;
	double		p1;

	
	p1 = sqrt(r.r * r.r + r.g * r.b);
	r.r = sqrt(2.0 / (p1 + 1)) * z.r * 255;
	r.g = sqrt(2.0 / (p1 + 1)) * z.i * 255;
	r.b = (r.r + r.g) / 2.0;
	return (r);
}