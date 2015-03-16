/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:33:03 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:33:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
** 10 : Hyperbolic
*/

t_cplx			hyper(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = sin (theta) / r;
	z.i = r * cos (theta);
	return (z);
}

/*
** 11 : Diamond
*/

t_cplx			diamond(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = sin (theta) * cos (r);
	z.i = cos (theta) * sin (r);
	return (z);
}

/*
** 12 : Ex
*/

t_cplx			f_exp(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;
	double		p0;
	double		p1;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	p0 = sin (theta + r);
	p0 = p0 * p0 * p0;
	p1 = cos (theta - r);
	p1 = p1 * p1 * p1;
	z.r = r * (p0 + p1);
	z.i = r * (p0 - p1);
	return (z);
}

/*
** 13 : Julia 
*/

t_cplx			f_julia(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (sqrt (x * x + y * y));
	theta = atan2 (y, x) * .5;
	if (random_bit ())
		theta += M_PI;
	z.r = r * cos(theta);
	z.i = r * sin(theta);
	return (z);
}

/*
** 14 : Bent
*/

t_cplx			bent(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	if (x >= 0.0 && y >= 0.0)
	{
		z.r = x;
		z.i = y;
	}
	else if (x < 0.0 && y >= 0.0)
	{
		z.r = 2.0 * x;
		z.i = y;
	}
	else if (x >= 0.0 && y < 0.0)
	{
		z.r = x;
		z.i = y * .5;
	}
	else if (x < 0.0 && y < 0.0)
	{
		z.r = 2.0 * x;
		z.i = y * .5;
	}
	return (z);
}
