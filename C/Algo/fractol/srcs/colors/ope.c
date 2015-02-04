/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:09:03 by msarr             #+#    #+#             */
/*   Updated: 2015/02/03 20:09:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		subc(t_rgb a, t_rgb b)
{
	t_rgb	vect;

	vect.r = a.r - b.r;
	vect.g = a.g - b.g;
	vect.b = a.b - b.b;
	return (vect);
}

t_rgb		multc(t_rgb v, double b)
{
	v.r *= b;
	v.g *= b;
	v.b *= b;
	return (v);
}

t_rgb		addc(t_rgb vect, t_rgb vect1)
{
	t_rgb	v;

	v.r = vect.r + vect1.r;
	v.g = vect.g + vect1.g;
	v.b = vect.b + vect1.b;
	return (v);
}

t_rgb		add2c(t_rgb a, double d)
{
	t_rgb	v;

	v.r = a.r + d;
	v.g = a.g + d;
	v.b = a.b + d;
	return (v);
}


t_rgb		cosc(t_rgb v)
{
	v.r = cos(v.r);
	v.g = cos(v.g);
	v.b = cos(v.b);
	return (v);
}
