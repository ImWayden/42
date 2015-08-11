/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 11:06:25 by msarr             #+#    #+#             */
/*   Updated: 2015/08/11 11:06:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx		cplx_sqrt(t_cplx a)
{
	t_cplx	c;

	c.r = a.r * a.r -  a.i * a.i;
	c.i = 2.0 * a.r * a.i;
	return (c);
}

t_cplx		cplx_pow(t_cplx z, double n)
{
	double	h;
	double	lr;
	double	li;
	double	a;
	
	h = mod(z);
	lr = pow(h, n);
	a = atan2(z.i, z.r);
	li = n * a;
	return (cplx(lr * cos(li), lr * sin(li)));
}

t_cplx 		cplx_cos(t_cplx z)
{
	double	a;
	double	b;

	a = exp(z.i);
	b = 1.0 / a;
	a = a / 2.0;
	b = b/2.0;
	return (cplx(cos(z.r) * (a + b), - sin(z.r ) * (a - b)));
}
