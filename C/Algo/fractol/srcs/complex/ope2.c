/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 11:06:39 by msarr             #+#    #+#             */
/*   Updated: 2015/08/11 11:06:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		mod(t_cplx a)
{
	double	d;

	d = a.r * a.r + a.i * a.i;
	return sqrt(d);
}

double		dot(t_cplx a, t_cplx b)
{
	double	d;

	d = 0.0;
	d += (a.r * b.r);
	d += (a.i * b.i);
	return (d);
}

double		 args(t_cplx c)
{
	return (atan2(c.r, c.i));
}
