/* ************************************************************************** */
/*																																													 */
/*																																	 :::			 ::::::::   */
/*   funct.c																								    :+:			 :+:    :+:   */
/*																														  +:+ +:+			    +:+			*/
/*   By: msarr <msarr@student.42.fr>									 +#+  +:+			  +#+			   */
/*																											   +#+#+#+#+#+   +#+						 */
/*   Created: 2015/01/26 14:06:45 by msarr						   #+#    #+#						   */
/*   Updated: 2015/01/26 14:06:45 by msarr						  ###   ########.fr			  */
/*																																													 */
/* ************************************************************************** */

#include "fractol.h"

/*
** 00 : Linear
*/

t_cplx			linear(t_env *env, double x, double y) 
{
	t_cplx		z;

	z.r = x;
	z.i = y;
}

/*
** 01 : Sinusoidal
*/

t_cplx			sinusoidal(t_env *env, double x, double y)
{
	t_cplx		z;

	z.r = sin(x);
	z.i = sin(y);
}

/*
** 02 :Spherical
*/

t_cplx			spherical(t_env *env, double x, double y)
{
	t_cplx		z;
	double		r;

	r = 1.0 / (x * x + y * y);
	z.r = r * x;
	z.i = r * y;
}

/*
** 03 : Swirl
*/

t_cplx			swirl(t_env *env, double x, double y)
{
	t_cplx		z;
	double		r;

	r = x * x + y * y;
	z.r = x * sin(r) - y * cos(r);
	z.i = x * cos(r) + y * sin(r);
}

/*
** 04 Horseshoe
*/

t_cplx			horseshoe(t_env *env, double x, double y)
{
	t_cplx		z;
	double		r;

	r = 1.0 / sqrt (x * x + y * y);
	z.r = r * (x - y) * (x + y);
	z.i = r * 2.0 * x * y;
}

/*
** 05 : Polar
*/

t_cplx			polar(t_env *env, double x, double y)
{
	t_cplx		z;

	z.r = atan2(y, x) / M_PI;
	z.i = sqrt(x * x + y * y) - 1.0;
}

/*
** 06 : Handkerchief
*/

t_cplx			handker(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = r * sin(theta + r);
	z.i = r * cos(theta - r);
}

/*
** 07 : Heart
*/

t_cplx			heart(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = r * sin (theta * r);
	z.i = -r * cos (theta * r);
}

/*
** 08 : Disk
*/

t_cplx			disk(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (x * x + y * y) * M_PI;
	theta = atan2 (y, x) / M_PI;
	z.r = theta * sin (r);
	z.i = theta * cos (r);
}

/*
** 09 : Spiral
*/

t_cplx			spiral(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = (1.0 / r) * (cos (theta) + sin (r));
	z.i = (1.0 / r) * (sin (theta) - cos (r));
}

/* 
** 10 : Hyperbolic
*/

t_cplx			hyper(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = sin (theta) / r;
	z.i = r * cos (theta);
}

/*
** 11 : Diamond
*/

t_cplx			diamond(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	z.r = sin (theta) * cos (r);
	z.i = cos (theta) * sin (r);
}

/*
** 12 : Ex
*/

t_cplx			f_exp(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;
	double		p0;
	double		p1;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	p0 = sin (theta + r);
	p0 = p0 * p0 * p0;
	p1 = cos (theta - r);
	p1 = p1 * p1 * p1;
	z.r = r * (p0 + p1);
	z.i = r * (p0 - p1);
}

/*
** 13 : Julia 
*/

t_cplx			f_julia(t_env *env, double x, double y)
{
	double		r;
	t_cplx		z;
	double		theta;

	r = sqrt (sqrt (x * x + y * y));
	theta = atan2 (y, x) * .5;
	if (random_bit ())
		theta += M_PI;
	z.r = r * cos(theta);
	z.i = r * sin(theta);
}

/*
** 14 : Bent
*/

t_cplx			bent(t_env *env, double x, double y)
{
	t_cplx		z;

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
}

/*
** 15 : Waves
*/

t_cplx			waves(t_env *env, double x, double y)
{
	t_cplx		z;

	z.r = x + env->colormap[i].pa1 * sin (y / (env->colormap[i].pa2 * env->colormap[i].pa2));
	z.i = y + env->colormap[i].pa3 * sin (x / (env->colormap[i].pa4 * env->colormap[i].pa4));
}

/*
** 16 : Fisheye
*/

t_cplx			fisheye(t_env *env, double x, double y)
{
	t_cplx		z;
	double		r;

	r = 2.0 / (1. + sqrt (x * x + y * y));
	z.r = r * y;
	z.i = r * x;
}

/*
** 17 : Popcorn
*/

t_cplx			popcorn(t_env *env, double x, double y)
{ 
	t_cplx		z;

	z.r = x + c * sin (tan (3.0 * y));
	z.i = y + f * sin (tan (3.0 * x));
}

/* Exponential */


t_cplx			funct(t_env *env, double x, double y)
{
	t_cplx		z;
// 	z.r = exp (x - 1.0) * cos (M_PI * y);
// 	z.i = exp (x - 1.0) * sin (M_PI * y);
// }

// t_cplx			funct(t_env *env, double x, double y)
// {
	t_cplx		z;
 19/* Power */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	z.r = pow (r, sin (theta)) * cos (theta);
// 	z.i = pow (r, sin (theta)) * sin (theta);
// }

// t_cplx			funct(t_env *env, double x, double y)
// { 20/* Cosine */
// 	z.r = cos (M_PI * x) * cosh (y);
// 	z.i = -sin (M_PI * x) * sinh (y);
// }

// t_cplx			funct(t_env *env, double x, double y)
// { 21/* Rings */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	prefix = modulus ((r + env->colormap[i].pa2 * env->colormap[i].pa2),
// 			 (2.0 * env->colormap[i].pa2 * env->colormap[i].pa2)) - (env->colormap[i].pa2 * env->colormap[i].pa2) + (r * (1.0 - env->colormap[i].pa2 * env->colormap[i].pa2));
// 	z.r = prefix * cos (theta);
// 	z.i = prefix * sin (theta);
// }
// t_cplx			funct(t_env *env, double x, double y){ 22/* Fan */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	t = M_PI * c * c;
// 	if (modulus (theta, t) > (t * .5))
// 		{
// 		  z.r = r * cos (theta - (t * .5));
// 		  z.i = r * sin (theta - (t * .5));
// 		}
// 	else
// 		{
// 		  z.r = r * cos (theta + (t * .5));
// 		  z.i = r * sin (theta + (t * .5));
// 		}
// }
// t_cplx			funct(t_env *env, double x, double y){ 23/* Eyefish */
// 	r = 2.0 / (1. + sqrt (x * x + y * y));
// 	z.r = r * x;
// 	z.i = r * y;
// }
// t_cplx			funct(t_env *env, double x, double y){ 24/* Bubble */
// 	r = 4 + x * x + y * y;
// 	z.r = (4.0 * x) / r;
// 	z.i = (4.0 * y) / r;
// }
// t_cplx			funct(t_env *env, double x, double y){ 25/* Cylinder */
// 	z.r = sin (x);
// 	z.i = y;
// }
// t_cplx			funct(t_env *env, double x, double y){ 26/* Tangent */
// 	z.r = sin (x) / cos (y);
// 	z.i = tan (y);
// }
// t_cplx			funct(t_env *env, double x, double y){ 27/* Cross */
// 	r = sqrt (1.0 / ((x * x - y * y) * (x * x - y * y)));
// 	z.r = x * r;
// 	z.i = y * r;
// }
// t_cplx			funct(t_env *env, double x, double y){ 28/* Collatz */
// 	z.r = .25 * (1.0 + 4.0 * x - (1.0 + 2.0 * x) * cos (M_PI * x));
// 	z.i = .25 * (1.0 + 4.0 * y - (1.0 + 2.0 * y) * cos (M_PI * y));
// }
// t_cplx			funct(t_env *env, double x, double y){ 29/* Mobius */
// 	t = (env->colormap[i].pa3 * x + env->colormap[i].pa4) * (env->colormap[i].pa3 * x + env->colormap[i].pa4) + env->colormap[i].pa3 * y * env->colormap[i].pa3 * y;
// 	z.r =
// 		((env->colormap[i].pa1 * x + env->colormap[i].pa2) * (env->colormap[i].pa3 * x + env->colormap[i].pa4) + env->colormap[i].pa1 * env->colormap[i].pa3 * y * y) / t;
// 	z.i =
// 		(env->colormap[i].pa1 * y * (env->colormap[i].pa3 * x + env->colormap[i].pa4) - env->colormap[i].pa3 * y * (env->colormap[i].pa1 * x + env->colormap[i].pa2)) / t;
// }
// t_cplx			funct(t_env *env, double x, double y){ 30/* Blob */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	z.r =
// 		r * (env->colormap[i].pa2 +
// 					0.5 * (env->colormap[i].pa1 - env->colormap[i].pa2) * (sin (env->colormap[i].pa3 * theta) +
// 					  1)) * cos (theta);
// 	z.i =
// 		r * (env->colormap[i].pa2 +
// 					0.5 * (env->colormap[i].pa1 - env->colormap[i].pa2) * (sin (env->colormap[i].pa3 * theta) +
// 					  1)) * sin (theta);
// }
// t_cplx			funct(t_env *env, double x, double y){ 31/* Noise */
// 	theta = RANDR (0, 1.);
// 	r = Rt_env *env, double x, double y){ 33/* Square */
// 	z.r = RANDR (0, 1.) - 0.5;
// 	z.i = RANDR (0, 1.) - 0.5;
// }
// t_cplx			funct(t_env *env, double x, double y){ 34/* Not Broken Waves */
// 	z.r = x + b * sin (y / pow (c, 2.0));
// 	z.i = y + e * sin (x / pow (f, 2.0));
// }
// /*
// **
//*/
t_cplx			curl(t_env *env, double x, double y)
{
	static double	p1 = 0.3;
	static double	p2 = -0.7;
	double			t1;
	double			t2;

	t1 = 1 + p1 * x + p2 * (x * x - y * y);
	t2 = p1 * y + 2 * p2 * x * y;
	z.r = (1 / (t1 * t1 + t2 * t2)) * (x * t1 + y * t2);
	z.i = (1 / (t1 * t1 + t2 * t2)) * (y * t1 - x * t2);
}

t_cplx			cross(t_env *env, double x, double y) // Cross (Variation 48)
{
	double		c;
	t_cplx		z;

	(t_cplx)env;
	c = sqrt(pow(x * x - y * y, -2));
    z.r = x * c;
    z.i = y * c;
    return (z);
}