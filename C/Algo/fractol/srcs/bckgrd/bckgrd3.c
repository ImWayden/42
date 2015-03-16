/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:33:20 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:33:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 15 : Waves
*/

t_cplx			waves(t_coeff col, double x, double y)
{
	t_cplx		z;

	z.r = x + col.pa1 * sin (y / (col.pa2 * col.pa2));
	z.i = y + col.pa3 * sin (x / (col.pa4 * col.pa4));
	return (z);
}

/*
** 16 : Fisheye
*/

t_cplx			fisheye(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 2.0 / (1. + sqrt (x * x + y * y));
	z.r = r * y;
	z.i = r * x;
	return (z);
}



/*
** 17 : Popcorn
*/

t_cplx			popcorn(t_coeff col, double x, double y)
{ 
	t_cplx		z;

	z.r = x + col.cc * sin(tan(3.0 * y));
	z.i = y + col.fc * sin(tan(3.0 * x));
	return (z);
}

/*
** 18 : Exponential
*/


t_cplx			exponential(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.i = exp(x - 1.0) * sin(M_PI * y);
	z.r = exp(x - 1.0) * cos(M_PI * y);
	return (z);
}

/*
** 19 : Power
*/

t_cplx			power(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;
	double		theta;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = pow(r, sin(theta)) * cos(theta);
	z.i = pow (r, sin(theta)) * sin(theta);
	return (z);
}
