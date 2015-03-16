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

