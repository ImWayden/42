/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 11:11:50 by msarr             #+#    #+#             */
/*   Updated: 2015/08/11 11:11:52 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx		formula(t_cplx z)
{
	t_cplx	real;
	t_cplx	imag;
	t_cplx	z2;
	t_cplx	z3;

	real = cplx(1.0, 0.0);
	imag = cplx(0.0, 1.0);
	z2 = cplx_mult(cplx_sqrt(cplx_add(z, real)), cplx_sub(z, real));
	z3 =  cplx_mult(cplx_add(z, imag), cplx_sqrt(cplx_sub(z, imag)));
	z = cplx_div(z2, z3);
	return (z);
}

t_cplx		toangle(t_cplx z)
{
	double	r;
	double	theta;
	double	phi;

	r = dot(z, z);
	phi = 2.0 * atan(1.0 / r);
	theta = atan2(z.i, z.r);
	return (cplx(phi,theta));
}