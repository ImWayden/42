/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:25:11 by msarr             #+#    #+#             */
/*   Updated: 2015/02/03 17:25:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fractol.h"

double		clamp(double value, double min, double max)
{
	double result;

	result = value;
	if (value > max)
		result = max;
	if (value < min)
		result = min;
	return result;
}

t_rgb		basic(t_cplx z, t_rgb color)
{
	if (z.r > 0 && z.i > 0)
		color = Green;
	else if (z.r < 0 && z.i < 0)
		color = Yellow;
	else
		color = Red;
	return (color);
}


t_rgb		style2(t_cplx z, t_rgb color, int i)
{
	double co;
	double co2;
	double fac;
	t_rgb	c;
	t_cplx	a;

	//co = (double)i + 1.0 - log2(0.5 * log2(dot(z, z)));
	//co = sqrt(co / 256.0);
	//co2 = mod(z);
	(void)i;
	(void)color;
	a = toangle(z);
	co = a.r;
	co = sqrt(co / 256.0);
	co2 = mod(a);
	fac = clamp(1.0 / pow(co2, Power), 0.0, 1.0);
	c.r = (.5 + .5 * cos(6.2831 * co)) * fac * 255.0;
	c.g = (.5 + .5 * cos(6.2831 * co)) * fac * 255.0;
	c.b = (.5 + .5 * cos(6.2831 * co)) * fac * 255.0;
	return (c);
}



