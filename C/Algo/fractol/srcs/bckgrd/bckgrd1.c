/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:32:56 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:32:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*
** 05 : Polar
*/

t_cplx			polar(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = atan2(y, x) / M_PI;
	z.i = sqrt(x * x + y * y) - 1.0;
	return (z);
}

/*
** 06 : Handkerchief
*/

t_cplx			handker(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = r * sin(theta + r);
	z.i = r * cos(theta - r);
	return (z);
}

/*
** 07 : Heart
*/

t_cplx			heart(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = r * sin(theta * r);
	z.i = -r * cos(theta * r);
	return (z);
}

/*
** 08 : Disk
*/

t_cplx			disk(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y) * M_PI;
	theta = atan2 (y, x) / M_PI;
	z.r = theta * sin (r);
	z.i = theta * cos (r);
	return (z);
}

/*
** 09 : Spiral
*/

t_cplx			spiral(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = (1.0 / r) * (cos (theta) + sin (r));
	z.i = (1.0 / r) * (sin (theta) - cos (r));
	return (z);
}
