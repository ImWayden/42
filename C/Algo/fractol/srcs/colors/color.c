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

#include "colors.h"
#include <stdio.h>

t_rgb		rgb(int r, int g, int b)
{
	t_rgb	vect;

	vect.r = r;
	vect.g = g;
	vect.b = b;
	return (vect);
}

t_rgb2		rgb2(double r, double g, double b)
{
	t_rgb2	vect;

	vect.r = r;
	vect.g = g;
	vect.b = b;
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
	printf("%i %i %i\n", r.r, r.g, r.b);
	return (c);
}
