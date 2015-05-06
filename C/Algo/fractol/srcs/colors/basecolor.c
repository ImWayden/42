/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basecolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 09:40:06 by msarr             #+#    #+#             */
/*   Updated: 2015/05/06 09:40:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		basecolor(t_cplx z)
{
	double r;
	double phi;
	double theta;
	t_rgb	v;
	
	z = formula(z);
	r = phase(z.r, z.i);
	phi = 2.0 * atan(1.0 / r);
	theta = atan2(z.r, z.i);
	v = rgb_mult(hsltorgb(hsl(theta, r, phi)), 255.0);
	return (v);
}

