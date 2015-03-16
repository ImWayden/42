/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:33:44 by msarr             #+#    #+#             */
/*   Updated: 2015/03/08 22:33:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
** 31 : Noise
*/

t_cplx			noise(t_coeff col, double x, double y)
{
	double		theta;
	t_cplx		z;
	double		r;

	(void)col;
	theta = RANDR(0, 1.0);
	r = RANDR(0, 1.0);
	z.r = theta * x * cos(2.0 * M_PI * r);
	z.i = theta * y * sin(2.0 * M_PI * r);
	return (z);
}

/* 
** 34 : Blur
*/

t_cplx			blur(t_coeff col, double x, double y)
{
	double		theta;
	t_cplx		z;
	double		r;

	(void)col;
	(void)x;
	(void)y;
	theta = RANDR(0, 1.0);
	r = RANDR(0, 1.0);
	z.r = theta * cos(2.0 * M_PI * r);
	z.i = theta * sin(2.0 * M_PI * r);
	return (z);
}
