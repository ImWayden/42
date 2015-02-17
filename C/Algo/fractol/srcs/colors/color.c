/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:13:19 by msarr             #+#    #+#             */
/*   Updated: 2015/01/24 11:13:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		rgb(double r, double g, double b)
{
	t_rgb	vect;

	vect.r = clamp(r, 0.0, 255.0);
	vect.g = clamp(g, 0.0, 255.0);
	vect.b = clamp(b, 0.0, 255.0);;
	return (vect);
}

t_hsl		hsl(double h, double s, double l)
{
	t_hsl	vect;

	vect.h = h;
	vect.s = s;
	vect.l = l;
	return (vect);
}

t_hsv		hsv(double h, double s, double v)
{
	t_hsv	vect;

	vect.h = h;
	vect.s = s;
	vect.v = v;
	return (vect);
}

t_color		color(t_rgb r)
{
	t_color	c;

	c.ac = RANDR (-1.5, 1.5);
	c.bc = RANDR (-1.5, 1.5);
	c.cc = RANDR (-1.5, 1.5);
	c.dc = RANDR (-1.5, 1.5);
	c.ec = RANDR (-1.5, 1.5);
	c.fc = RANDR (-1.5, 1.5);
	c.pa1 = RANDR (-2, 2);
	c.pa2 = RANDR (-2, 2);
	c.pa3 = RANDR (-2, 2);
	c.pa4 = RANDR (-2, 2);
	c.rgb = rgb(r.r, r.g, r.b);
	return (c);
}
