/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 16:04:21 by msarr             #+#    #+#             */
/*   Updated: 2014/12/24 15:35:23 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect		color_makeFromRGBhex(unsigned int c)
{
	return (new(c, c >> 8, c >> 16));
}

t_vect		c_addweighted(t_vect a, double w, t_vect b, double w1)
{
	double	sum;
	t_vect	c;

	sum = w + w1;
	c.x = ((a.x * w) + (b.x * w1)) / sum;
	c.y = ((a.y * w) + (b.y * w1)) / sum;
	c.z = ((a.z * w) + (b.z * w1)) / sum;
	return (c);
}

t_vect		color_blend(t_vect a, double w, t_vect b)
{
	double	w1;

	w = LIMIT(w, 0.0, 1.0);
	w1 = 1.0 - w;
	return (c_addweighted(a, w, b, w1));
}

t_vect		get_color(t_vect color, t_shading light, double amb)
{
	double	d;

	d = 1.0 - amb;
	color = mult2(color, amb + light.diff * d);
	color = add(color, mult2(COLOR_WHITE, light.spec));
	return (color);
}
