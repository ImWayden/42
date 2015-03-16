/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:33:28 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:33:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 20 : Cosine
*/

t_cplx			cosine(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = cos(M_PI * x) * cosh(y);
	z.i = -sin(M_PI * x) * sinh(y);
	return (z);
}

/*
** 21 : Rings
*/

t_cplx			rings(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;
	double		theta;
	double		prefix;

	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	prefix = mod(cplx((r + col.pa2 * col.pa2)
		, (2.0 * col.pa2 * col.pa2))) - (col.pa2 * col.pa2)
		+ (r * (1.0 - col.pa2 * col.pa2));
	z.r = prefix * cos(theta);
	z.i = prefix * sin(theta);
	return (z);
}

/*
** 22 : Fan
*/

t_cplx			fan(t_coeff col, double x, double y)
{
	double		r;
	double		theta;
	double		t;
	t_cplx		z;

	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	t = M_PI * col.cc * col.cc;
	if (mod(cplx(theta, t)) > (t * 0.5))
	{
		z.r = r * cos(theta - (t * .5));
		z.i = r * sin(theta - (t * .5));
	}
	else
	{
		z.r = r * cos(theta + (t * 0.5));
		z.i = r * sin(theta + (t * 0.5));
	}
	return (z);
}

/*
** 23 : Blob
*/

t_cplx			blob(t_coeff col, double x, double y)
{
	double		r;
	double		theta;
	t_cplx		z;

	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = r * (col.pa2 + 0.5 * (col.pa1 - col.pa2) * (sin (col.pa3 * theta) + 1)) * cos (theta);
	z.i = r * (col.pa2 + 0.5 * (col.pa1 - col.pa2) * (sin(col.pa3 * theta) + 1)) * sin(theta);
	return (z);
}

/*
** 24 : PDJ
*/

t_cplx		pdj(t_coeff col, double x, double y)
{
	t_cplx	z;
 //    double pdj1 = 1.2;
	// double pdj2 = 2.0;
	// double pdj3 = 1.5;
	// double pdj4 = 2;

	z.r = sin(col.ac * y) - cos(col.bc * x);
	z.i = sin(col.cc * x) - cos(col.dc * y);
	return (z);
}