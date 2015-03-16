/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:33:36 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:33:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*
** 25 : Fan2
*/

t_cplx		fan2(t_coeff col, double x, double y) 
{
	double	r;
	double	theta;
	t_cplx		z;
	double	p1;
	double	p2;
	double	fan2x = 0.8;
	double	fan2y = -0.33;
	double	t;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	p1 = M_PI * fan2x * fan2x;
	p2 = fan2y;
	t = theta + p2 - p1 * (int)((2.0 * theta * p2) / p1);
	if(t > p1 / 2)
	{
		z.r = r * sin(theta - p1 / 2.0);
		z.i = r * cos(theta - p1/ 2.0);
	}
	else
	{
		z.r = r * sin(theta + p1 / 2.0);
		z.i = r * cos(theta + p1 / 2.0);
	}
	return (z);
}

/*
** 26 : Rings2
*/

t_cplx		rings2(t_coeff col, double x, double y)
{
	double	r;
	double	p;
	t_cplx	z;
	double	t;
	double	rings2val = 0.4;

	(void)col;
	p = rings2val * rings2val;
	r = sqrt(x * x + y * y);
	t = r - 2.0 * p * floor(r + p ) / (0.5 * p) + r * (1 - p);
	z.r = t * sin(t);
	z.i = t * cos(t);
	return (z);
}

/*
** 27 : Eyefish
*/

t_cplx			eyefish(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 2.0 / (1. + sqrt (x * x + y * y));
	z.r = r * x;
	z.i = r * y;
	return (z);
}

/*
** 28 : Bubble
*/

t_cplx			bubble(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 4 + x * x + y * y;
	z.r = (4.0 * x) / r;
	z.i = (4.0 * y) / r;
	return (z);
}

/*
** 29 : Cylinder
*/

t_cplx			cylinder(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = sin(x);
	z.i = y;
	return (z);
}