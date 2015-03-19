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

t_cplx 		cplx_cos(t_cplx z )
{
	double	a;
	double	b;

	a = exp(z.i);
	b = 1.0 / a;
	a = a / 2.0;
	b = b/2.0;
	return (cplx(cos(z.r) * (a + b), - sin(z.r ) * (a - b)));
}

t_cplx		cplx(double r, double i)
{
	t_cplx	c;

	c.r = r;
	c.i = i;
	return (c);
}

t_cplx		cplx_sub(t_cplx a, t_cplx b)
{
	t_cplx	vect;

	vect.r = a.r - b.r;
	vect.i = a.i - b.i;
	return (vect);
}


t_cplx		cplx_add(t_cplx vect, t_cplx vect1)
{
	t_cplx	v;

	v.r = vect.r + vect1.r;
	v.i = vect.i + vect1.i;
	return (v);
}

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

t_cplx 		cplx_mult(t_cplx a, t_cplx b)
{
	t_cplx	c;

	c.r = a.r * b.r -  a.i * b.i;
	c.i = a.r * b.i + a.i * b.r;
	return (c);
}

t_cplx		cplx_sqrt(t_cplx a)
{
	t_cplx	c;

	c.r = a.r * a.r -  a.i * a.i;
	c.i = 2.0 * a.r * a.i;
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

t_cplx		formula(t_cplx z)
{
	t_cplx	real;
	t_cplx	imag;
	t_cplx	z2;
	t_cplx	z3;

	real = cplx(1.0, 0.0);
	imag = cplx(0.0, 1.0);
	z2 = cplx_mult(cplx_sqrt(cplx_add(z, real)), cplx_sub(z, real));
	z3 =  cplx_mult(cplx_add(z, imag), cplx_sqrt(cplx_sub(z, imag)));
	z = cplx_div(z2, z3);
	return (z);
}

t_cplx		toangle(t_cplx z)
{
	double	r;
	double	theta;
	double	phi;

	r = dot(z, z);
	phi = 2.0 * atan(1.0 / r);
	theta = atan2(z.i, z.r);
	return (cplx(phi,theta));
}
