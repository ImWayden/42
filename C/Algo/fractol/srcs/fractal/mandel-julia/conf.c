/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 12:36:58 by msarr             #+#    #+#             */
/*   Updated: 2015/01/25 12:36:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_cplx		new(double x, double y)
{
	t_cplx	c;

	c.r = x;
	c.i = y;
	return (c);
}

t_cplx		conf(double i)
{
	double r = -1.0; 
	double im = 1.0; 
	
	r +=  ((int)(i / 6)) * 0.2;
	r -= r > 0 ? 0.01 : 0.0;
	if (r > 1.0)
		r = -1.0;
	im -=  ((int)i % 6) * 0.2;
	if (im < 0)
		im = 1;
	return (new(r, im));
}
