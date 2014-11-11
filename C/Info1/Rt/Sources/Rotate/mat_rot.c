/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:54:16 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:09:46 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "math.h"

void		rotate_z(double *x, double *y, double *z, double a)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;

	if (a != 0.0)
	{
		a = (a * 3.14159264) / 180;
		tmpx = ((*x) * cos(a)) + ((*y) * -sin(a)) + ((*z) * 0.0);
		tmpy = ((*x) * sin(a)) + ((*y) * cos(a)) + ((*z) * 0.0);
		tmpz = ((*x) * 0.0) + ((*y) * 0.0) + ((*z) * 1.0);
		*x = tmpx;
		*y = tmpy;
		*z = tmpz;
	}
}

void		rotate_y(double *x, double *y, double *z, double a)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;

	if (a != 0.0)
	{
		a = (a * 3.14159264) / 180;
		tmpx = ((*x) * cos(a)) + ((*y) * 0.0) + ((*z) * sin(a));
		tmpy = ((*x) * 0.0) + ((*y) * 1.0) + ((*z) * 0.0);
		tmpz = ((*x) * -sin(a)) + ((*y) * 0.0) + ((*z) * cos(a));
		*x = tmpx;
		*y = tmpy;
		*z = tmpz;
	}
}

void		rotate_x(double *x, double *y, double *z, double a)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;

	if (a != 0.0)
	{
		a = (a * 3.14159264) / 180;
		tmpx = ((*x) * 1.0) + ((*y) * 0.0) + ((*z) * 0.0);
		tmpy = ((*x) * 0.0) + ((*y) * cos(a)) + ((*z) * -sin(a));
		tmpz = ((*x) * 0.0) + ((*y) * sin(a)) + ((*z) * cos(a));
		*x = tmpx;
		*y = tmpy;
		*z = tmpz;
	}
}
