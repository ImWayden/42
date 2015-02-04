/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 21:55:07 by msarr             #+#    #+#             */
/*   Updated: 2015/02/01 21:55:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <stdio.h>

static double	hue2rgb(double p, double q, double t)
{
	if (t < 0.0)
		t += 1.0;
	if (t > 1)
		t -= 1.0;
	if (t < 1.0 / 6.0)
		return p + (q - p) * 6.0 * t;
	if (t < 1.0 / 2.0)
		return q;
	if (t < 2.0 / 3.0)
		return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
	return p;
}

t_rgb			hsltorgb(t_hsl h)
{
	double	q;
	double	p;

	if (h.s == 0.0)
		return (rgb(h.l * 255, h.l * 255, h.l * 255)); // achromatic
	q = h.l < 0.5 ? h.l * (1.0 + h.s) : h.l + h.s - h.l * h.s;
	p = 2.0 * h.l - q;
	printf("p = %lf ", p);
	return (rgb(hue2rgb(p, q, h.h + 1.0 / 3.0) * 255.0,
				hue2rgb(p, q, h.h) * 255.0,
				hue2rgb(p, q, h.h - 1.0 / 3.0) * 255.0));
}

t_hsl			rgbtohsl(t_rgb c)
{
	t_rgb2		p;
	t_hsl		h;
	double		min;
	double		max;
	double		d;

	p = rgb2(c.r / 255.0, c.g / 255.0, c.b / 255.0);
	max = MAX3(p.r, p.g, p.b);
	min = MIN3(p.r, p.g, p.b);
	h = hsl((max + min) / 2.0, (max + min) / 2.0, (max + min) / 2.0);
	if(max == min)
		return (hsl(0.0, 0.0, h.l));// achromatic
	d = max - min;
	h.s = h.l > 0.5 ? d / (2 - max - min) : d / (max + min);
	if (max == p.r)
		h.h = (p.g - p.b) / d + (p.g < p.b ? 6.0 : 0.0);
	else if (max == p.g)
		h.h = (p.b - p.r) / d + 2;
	else
		h.h = (p.r - p.g) / d + 4;
	h.h /= 6.0;
	return (h);
}

t_rgb			hsvtorgb(t_hsv hsv)
{
	int			hi;
	double		f;
	double		p;
	double		q;
	double		t;
	/// Implementation based on: http://en.wikipedia.org/wiki/HSV_color_space
	hsv.h = mod(hsv.h,2.*PI);
	hi = (int)(mod(hsv.h / (2.0 * M_PI / 6.0 ), 6.0));
	f = (hsv.h / (2.0 * M_PI / 6.0)) - (double)hi;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v*(1.0 - f * hsv.s);
	t = hsv.v*(1.0 - (1.0 - f) * hsv.s);
	if (hi == 0)
		return (rgb(hsv.v,t,p));
	if (hi == 1)
		return rgb(q,hsv.v,p);
	if (hi == 2)
		return rgb(p,hsv.v,t);
	if (hi == 3)
		return rgb(p,q,hsv.v);
	if (hi == 4)
		return rgb(t,p,hsv.v);
	if (hi == 5)
		return rgb(hsv.v,p,q);
	return rgb(0, 0, 0);
}