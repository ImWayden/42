/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bckgrd7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 00:11:00 by msarr             #+#    #+#             */
/*   Updated: 2015/03/09 00:11:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 39 : Curl
*/

t_cplx			curl(t_coeff col, double x, double y)
{
	double			p1 = 0.3;
	double			p2 = -0.7;
	double			t1;
	t_cplx			z;
	double			t2;

	(void)col;
	t1 = 1 + p1 * x + p2 * (x * x - y * y);
	t2 = p1 * y + 2 * p2 * x * y;
	z.r = (1 / (t1 * t1 + t2 * t2)) * (x * t1 + y * t2);
	z.i = (1 / (t1 * t1 + t2 * t2)) * (y * t1 - x * t2);
	return (z);
}