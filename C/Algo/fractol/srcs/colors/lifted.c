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
	return (hsltorgb(hsl(in, phase(z.r, z.i), sat)));
}