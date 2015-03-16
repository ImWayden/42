/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:14:19 by msarr             #+#    #+#             */
/*   Updated: 2015/02/04 13:14:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		basecolor(t_cplx z, t_rgb color)
{
	double r;
	double phi;
	double theta;
	t_rgb	v;
	double s;
	double val;
	
	z = formula(z);
	r = dot(z, z);
	phi = 2.0 * atan(1.0 / r);
	theta = atan2(z.r, z.i);
	s = 1.0;
	val = 1.0;
	if (phi < M_PI / 2.0)
		s = sin(phi);
	else
		val = sin(phi);
	s = pow(s, 0.5);
	val = pow(val, 0.5);
	v = linear_inter(rgb_mult(hsvtorgb(hsv(theta, s, val)), 255.0), color, 0.5);
	return v;
}

double		phase1(double x, double y)
{
	double	angle;

	if (!x)
	{
    	if (y > 0)
    		angle = M_PI / 2;
    	else
    		angle = -M_PI / 2;
    }
    else
    	angle = atan(y / x);
    if (x < 0)
    	angle = angle + M_PI;
    if (angle < 0)
    	angle = angle + 2 * M_PI;
    angle = angle * 3 / M_PI;
    if (angle == 6)
    	angle = 0;
    return (angle);
}


t_rgb		ihs(double in, double hue, double sat)
{
	int ihue;
	int i;
	int k;
	int r;
	int b;
	int g;
	double rhue;

	i = round(255 * in);
	k = round(i * (1 - sat));
	rhue = hue;
	ihue = (int)rhue;
	rhue = rhue - ihue;
	if (!ihue)
	{
		r = i;
		g = round(i * sat * rhue * rhue * (3 - 2 * rhue)) + k;
		b = k;
	}
	if(ihue == 1)
	{
		g = i;
		r = round(i * sat * (1 + rhue * rhue * (2 * rhue - 3))) + k;
		b = k;
	}
	if (ihue == 2)
	{
		g = i;
		b = round(i * sat * rhue * rhue * (3 - 2 * rhue)) + k;
		r = k;
	}
	if (ihue == 3)
	{
		b = i;
		g = round(i * sat * (1 + rhue * rhue * (2 * rhue - 3))) + k;
		r = k;
	}
	if (ihue == 4)
	{
		b = i;
		r = round(i * sat * rhue * rhue * (3 - 2 * rhue)) + k;
		g = k;
	}
	if (ihue == 5)
	{
		r = i;
		b = round(i * sat * (1 + rhue * rhue * (2 * rhue - 3))) + k;
		g = k;
	}
	return (rgb(r, g, b));
}

t_rgb		getcolor(t_cplx z)
{
	double d;
	double in;
	double sat;
	int k;
	const double in0 = 0.6, sat0 = 0.3;

	d = dot(z, z);
	if (d >= 1)
		d = log(d);
	d = 4 * (d - (int)d);
	k = (int)d;
	d = d - k;
	if (!k)
	{
		in = 0.99;
		sat = 0.99 - (0.99 - sat0) * d;
	}
	if (k == 1)
	{
		in = 0.99 - (0.99 - in0) * d;
		sat = sat0;
	}
	if (k == 2)
	{
		in = in0;
		sat = 0.99 - (0.99 - sat0) * (1 - d);
	}
	if (k == 3)
	{
		in = 0.99 - (0.99 - in0) * (1 - d);
		sat = 0.99;
	}
	return (ihs(in, phase1(z.r, z.i), sat));
}