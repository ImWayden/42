/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:30:58 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:30:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 00 : Linear
*/

t_cplx			linear(t_coeff col, double x, double y) 
{
	t_cplx		z;

	(void)col;
	z.r = x;
	z.i = y;
	return (z);
}

/*
** 01 : Sinusoidal
*/

t_cplx			sinusoidal(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = sin(x);
	z.i = sin(y);
	return (z);
}

/*
** 02 :Spherical
*/

t_cplx			spherical(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 1.0 / (x * x + y * y);
	z.r = r * x;
	z.i = r * y;
	return (z);
}

/*
** 03 : Swirl
*/

t_cplx			swirl(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = x * x + y * y;
	z.r = x * sin(r) - y * cos(r);
	z.i = x * cos(r) + y * sin(r);
	return (z);
}

/*
** 04 Horseshoe
*/

t_cplx			horseshoe(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 1.0 / sqrt (x * x + y * y);
	z.r = r * (x - y) * (x + y);
	z.i = r * 2.0 * x * y;
	return (z);
}
