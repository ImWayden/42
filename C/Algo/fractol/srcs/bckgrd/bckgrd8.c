/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 00:11:24 by msarr             #+#    #+#             */
/*   Updated: 2015/03/09 00:11:24 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 42 : tangent
*/

t_cplx			tangent(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = sin(x) / cos(y);
	z.i = tan(y);
	return (z);
}

/* 
** 43 : Square
*/

t_cplx			square(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	(void)x;
	(void)y;
	z.r = RANDR(0, 1.0) - 0.5;
	z.i = RANDR (0, 1.0) - 0.5;
	return (z);
}