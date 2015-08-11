/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 23:48:36 by msarr             #+#    #+#             */
/*   Updated: 2015/01/23 23:48:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx		cplx_add(t_cplx vect, t_cplx vect1)
{
	t_cplx	v;

	v.r = vect.r + vect1.r;
	v.i = vect.i + vect1.i;
	return (v);
}

t_cplx		cplx_sub(t_cplx a, t_cplx b)
{
	t_cplx	vect;

	vect.r = a.r - b.r;
	vect.i = a.i - b.i;
	return (vect);
}

t_cplx 		cplx_mult(t_cplx a, t_cplx b)
{
	t_cplx	c;

	c.r = a.r * b.r -  a.i * b.i;
	c.i = a.r * b.i + a.i * b.r;
	return (c);
}

t_cplx 		cplx_mult2(t_cplx a, double b)
{
	t_cplx	c;

	c.r = a.r * b;
	c.i = a.r * b;
	return (c);
}

t_cplx		cplx_div(t_cplx lhs, t_cplx rhs)
{
	double	c1;
	double	c2;
	double	d;

	d = rhs.r * rhs.r + rhs.i * rhs.i;
	if (d == 0)
		return (cplx(0.0, 0.0));
	c1 = lhs.r * rhs.r + lhs.i * rhs.i;
	c2 = lhs.i * rhs.r - lhs.r * rhs.i;
	return (cplx(c1 / d, c2 / d));
}
