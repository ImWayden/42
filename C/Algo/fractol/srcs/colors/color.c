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

t_rgb		rgb(int r, int g, int b)
{
	t_rgb	vect;

	vect.r = r;
	vect.g = g;
	vect.b = b;
	return (vect);
}

t_color		color()
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
	c.rgb = rgb((64 + RANDR (64, 256)), (64 + RANDR (64, 256))
				, (64 + RANDR (64, 256)));
	return (c);
}