/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 00:11:51 by msarr             #+#    #+#             */
/*   Updated: 2015/03/09 00:11:51 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
** 48 : Cross
*/

t_cplx			cross(t_coeff col, double x, double y)
{
	double		c;
	t_cplx		z;

	(void)col;
	c = sqrt(pow(x * x - y * y, -2));
    z.r = x * c;
    z.i = y * c;
    return (z);
}

/* 
** 48 : Collatz
*/

t_cplx			collatz(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = .25 * (1.0 + 4.0 * x - (1.0 + 2.0 * x) * cos (M_PI * x));
	z.i = .25 * (1.0 + 4.0 * y - (1.0 + 2.0 * y) * cos (M_PI * y));
	return (z);
}