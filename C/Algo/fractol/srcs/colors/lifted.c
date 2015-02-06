/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:14:19 by msarr             #+#    #+#             */
/*   Updated: 2015/02/04 13:14:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//zdxpt = toangle(formula(cplx_add(z , cplx(delta, 0.0))));
	//zdypt = toangle(formula(cplx_add(z, cplx(0.0, delta))));
	//zdp = sqrt(sqr(zdxpt.r - phi) + sqr(zdypt.r - phi)) / delta;
	//zdt = sqrt(sqr(zdxpt.i - theta) + sqr(zdypt.i - theta)) / delta;
	//	r = zdp; 

double sqr(double a) { return a; }


double delta = 1.0;

// Convert to
double GridWidth = 10;

double		fract(double x)
{
	return (x - floor(x));
}

t_rgb		basecolor(t_env *env)
{
	t_cplx z;
	double r;
	double phi;
	double theta;
	t_rgb	v;
	double b0; // fractional brightness
	double b; // fractional brightness
	double b1;        // ... for every second band
	double m; // twelve white rays.
	double p10; // grid width
	double s;
	double val;
	
	z = formula(env->z);
	r = dot(z, z);
	phi = 2.0 * atan(1.0 / r);
	theta = atan2(z.r, z.i);
	b0 = fract(2.0 * log(r) / log(2.)); // fractional brightness
	b1 = fract(log(r) / log(2.));        // ... for every second band
	m = mod(cplx(theta , M_PI / 6.)); // twelve white rays.
	p10 = pow(10.0 , GridWidth);
	b = (b0 + 1.0) / 2.0;
	if (b1 < 0.5)
		b = 1.0;
	s = 1.0;(void)m;(void)p10;
	val = 1.0;
	if (phi < M_PI / 2.0)
		s = sin(phi);
	else
		val = sin(phi);
	s = pow(s, 0.5);
	val = pow(val, 0.5);
	v = rgb_mult(hsvtorgb(hsv(theta, s, val)), b * 255.0);
	return v;
}
double Sigmoid(double x) {
	return (1.0/ (1.0+exp(-x/10.0)))-0.5;
}
double T(double x) {
	return 2.0* Sigmoid(abs(x+1./x));
}