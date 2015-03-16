/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:08:15 by msarr             #+#    #+#             */
/*   Updated: 2015/02/25 13:08:18 by msarr            ###   ########.fr       */
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

/*
** 05 : Polar
*/

t_cplx			polar(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = atan2(y, x) / M_PI;
	z.i = sqrt(x * x + y * y) - 1.0;
	return (z);
}

/*
** 06 : Handkerchief
*/

t_cplx			handker(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = r * sin(theta + r);
	z.i = r * cos(theta - r);
	return (z);
}

/*
** 07 : Heart
*/

t_cplx			heart(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = r * sin(theta * r);
	z.i = -r * cos(theta * r);
	return (z);
}

/*
** 08 : Disk
*/

t_cplx			disk(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y) * M_PI;
	theta = atan2 (y, x) / M_PI;
	z.r = theta * sin (r);
	z.i = theta * cos (r);
	return (z);
}

/*
** 09 : Spiral
*/

t_cplx			spiral(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = (1.0 / r) * (cos (theta) + sin (r));
	z.i = (1.0 / r) * (sin (theta) - cos (r));
	return (z);
}

/* 
** 10 : Hyperbolic
*/

t_cplx			hyper(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = sin (theta) / r;
	z.i = r * cos (theta);
	return (z);
}

/*
** 11 : Diamond
*/

t_cplx			diamond(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = sin (theta) * cos (r);
	z.i = cos (theta) * sin (r);
	return (z);
}

/*
** 12 : Ex
*/

t_cplx			f_exp(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;
	double		p0;
	double		p1;

	(void)col;
	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	p0 = sin (theta + r);
	p0 = p0 * p0 * p0;
	p1 = cos (theta - r);
	p1 = p1 * p1 * p1;
	z.r = r * (p0 + p1);
	z.i = r * (p0 - p1);
	return (z);
}

/*
** 13 : Julia 
*/

t_cplx			f_julia(t_coeff col, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	(void)col;
	r = sqrt (sqrt (x * x + y * y));
	theta = atan2 (y, x) * .5;
	if (random_bit ())
		theta += M_PI;
	z.r = r * cos(theta);
	z.i = r * sin(theta);
	return (z);
}

/*
** 14 : Bent
*/

t_cplx			bent(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	if (x >= 0.0 && y >= 0.0)
	{
		z.r = x;
		z.i = y;
	}
	else if (x < 0.0 && y >= 0.0)
	{
		z.r = 2.0 * x;
		z.i = y;
	}
	else if (x >= 0.0 && y < 0.0)
	{
		z.r = x;
		z.i = y * .5;
	}
	else if (x < 0.0 && y < 0.0)
	{
		z.r = 2.0 * x;
		z.i = y * .5;
	}
	return (z);
}

/*
** 15 : Waves
*/

t_cplx			waves(t_coeff col, double x, double y)
{
	t_cplx		z;

	z.r = x + col.pa1 * sin (y / (col.pa2 * col.pa2));
	z.i = y + col.pa3 * sin (x / (col.pa4 * col.pa4));
	return (z);
}

/*
** 16 : Fisheye
*/

t_cplx			fisheye(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 2.0 / (1. + sqrt (x * x + y * y));
	z.r = r * y;
	z.i = r * x;
	return (z);
}



/*
** 17 : Popcorn
*/

t_cplx			popcorn(t_coeff col, double x, double y)
{ 
	t_cplx		z;

	z.r = x + col.cc * sin(tan(3.0 * y));
	z.i = y + col.fc * sin(tan(3.0 * x));
	return (z);
}

/*
** 18 : Exponential
*/


t_cplx			exponential(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.i = exp(x - 1.0) * sin(M_PI * y);
	z.r = exp(x - 1.0) * cos(M_PI * y);
	return (z);
}

/*
** 19 : Power
*/

t_cplx			power(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;
	double		theta;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = pow(r, sin(theta)) * cos(theta);
	z.i = pow (r, sin(theta)) * sin(theta);
	return (z);
}

/*
** 20 : Cosine
*/

t_cplx			cosine(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = cos(M_PI * x) * cosh(y);
	z.i = -sin(M_PI * x) * sinh(y);
	return (z);
}

/*
** 21 : Rings
*/

t_cplx			rings(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;
	double		theta;
	double		prefix;

	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	prefix = mod(cplx((r + col.pa2 * col.pa2)
		, (2.0 * col.pa2 * col.pa2))) - (col.pa2 * col.pa2)
		+ (r * (1.0 - col.pa2 * col.pa2));
	z.r = prefix * cos(theta);
	z.i = prefix * sin(theta);
	return (z);
}

/*
** 22 : Fan
*/

t_cplx			fan(t_coeff col, double x, double y)
{
	double		r;
	double		theta;
	double		t;
	t_cplx		z;

	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	t = M_PI * col.cc * col.cc;
	if (mod(cplx(theta, t)) > (t * 0.5))
	{
		z.r = r * cos(theta - (t * .5));
		z.i = r * sin(theta - (t * .5));
	}
	else
	{
		z.r = r * cos(theta + (t * 0.5));
		z.i = r * sin(theta + (t * 0.5));
	}
	return (z);
}

/*
** 23 : Blob
*/

t_cplx			blob(t_coeff col, double x, double y)
{
	double		r;
	double		theta;
	t_cplx		z;

	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	z.r = r * (col.pa2 + 0.5 * (col.pa1 - col.pa2) * (sin (col.pa3 * theta) + 1)) * cos (theta);
	z.i = r * (col.pa2 + 0.5 * (col.pa1 - col.pa2) * (sin(col.pa3 * theta) + 1)) * sin(theta);
	return (z);
}

/*
** 24 : PDJ
*/

t_cplx		pdj(t_coeff col, double x, double y)
{
    t_cplx	z;
 //    double pdj1 = 1.2;
	// double pdj2 = 2.0;
	// double pdj3 = 1.5;
	// double pdj4 = 2;
  
    z.r = sin(col.ac * y) - cos(col.bc * x);
    z.i = sin(col.cc * x) - cos(col.dc * y);
	return (z);
}

/*
** 25 : Fan2
*/

t_cplx		fan2(t_coeff col, double x, double y) 
{
	double	r;
	double	theta;
	t_cplx		z;
	double	p1;
	double	p2;
	double	fan2x = 0.8;
	double	fan2y = -0.33;
	double	t;

	(void)col;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	p1 = M_PI * fan2x * fan2x;
	p2 = fan2y;
	t = theta + p2 - p1 * (int)((2.0 * theta * p2) / p1);
	if(t > p1 / 2)
	{
		z.r = r * sin(theta - p1 / 2.0);
		z.i = r * cos(theta - p1/ 2.0);
	}
	else
	{
		z.r = r * sin(theta + p1 / 2.0);
		z.i = r * cos(theta + p1 / 2.0);
	}
	return (z);
}

/*
** 26 : Rings2
*/

t_cplx		rings2(t_coeff col, double x, double y)
{
	double	r;
	double	p;
	t_cplx	z;
	double	t;
	double	rings2val = 0.4;

	(void)col;
	p = rings2val * rings2val;
	r = sqrt(x * x + y * y);
	t = r - 2.0 * p * floor(r + p ) / (0.5 * p) + r * (1 - p);
	z.r = t * sin(t);
	z.i = t * cos(t);
	return (z);
}

/*
** 27 : Eyefish
*/

t_cplx			eyefish(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 2.0 / (1. + sqrt (x * x + y * y));
	z.r = r * x;
	z.i = r * y;
	return (z);
}

/*
** 28 : Bubble
*/

t_cplx			bubble(t_coeff col, double x, double y)
{
	t_cplx		z;
	double		r;

	(void)col;
	r = 4 + x * x + y * y;
	z.r = (4.0 * x) / r;
	z.i = (4.0 * y) / r;
	return (z);
}

/*
** 29 : Cylinder
*/

t_cplx			cylinder(t_coeff col, double x, double y)
{
	t_cplx		z;

	(void)col;
	z.r = sin(x);
	z.i = y;
	return (z);
}

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

