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

void			linear(t_env *env, double x, double y) 
{
	env->z.r = x;
	env->z.i = y;
}

/*
** 01 : Sinusoidal
*/

void			sinusoidal(t_env *env, double x, double y)
{		
	env->z.r = sin(x);
	env->z.i = sin(y);
}

/*
** 02 :Spherical
*/

void			spherical(t_env *env, double x, double y)
{
	double		r;

	r = 1.0 / (x * x + y * y);
	env->z.r = r * x;
	env->z.i = r * y;
}

/*
** 03 : Swirl
*/

void			swirl(t_env *env, double x, double y)
{
	double		r;

	r = x * x + y * y;
	env->z.r = x * sin(r) - y * cos(r);
	env->z.i = x * cos(r) + y * sin(r);
}

/*
** 04 Horseshoe
*/

void			horseshoe(t_env *env, double x, double y)
{
	double		r;

	r = 1.0 / sqrt (x * x + y * y);
	env->z.r = r * (x - y) * (x + y);
	env->z.i = r * 2.0 * x * y;
}

/*
** 05 : Polar
*/

void			polar(t_env *env, double x, double y)
{
	env->z.r = atan2(y, x) / M_PI;
	env->z.i = sqrt(x * x + y * y) - 1.0;
}

/*
** 06 : Handkerchief
*/

void			handker(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	env->z.r = r * sin(theta + r);
	env->z.i = r * cos(theta - r);
}

/*
** 07 : Heart
*/

void			heart(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	env->z.r = r * sin (theta * r);
	env->z.i = -r * cos (theta * r);
}

/*
** 08 : Disk
*/

void			disk(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y) * M_PI;
	theta = atan2 (y, x) / M_PI;
	env->z.r = theta * sin (r);
	env->z.i = theta * cos (r);
}

/*
** 09 : Spiral
*/

void			spiral(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	env->z.r = (1.0 / r) * (cos (theta) + sin (r));
	env->z.i = (1.0 / r) * (sin (theta) - cos (r));
}

/* 
** 10 : Hyperbolic
*/

void			hyper(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	env->z.r = sin (theta) / r;
	env->z.i = r * cos (theta);
}

/*
** 11 : Diamond
*/

void			diamond(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	env->z.r = sin (theta) * cos (r);
	env->z.i = cos (theta) * sin (r);
}

/*
** 12 : Ex
*/

void			f_exp(t_env *env, double x, double y)
{
	double		r;
	double		theta;
	double		p0;
	double		p1;

	r = sqrt (x * x + y * y);
	theta = atan2 (y, x);
	p0 = sin (theta + r);
	p0 = p0 * p0 * p0;
	p1 = cos (theta - r);
	p1 = p1 * p1 * p1;
	env->z.r = r * (p0 + p1);
	env->z.i = r * (p0 - p1);
}

/*
** 13 : Julia 
*/

void			fjulia(t_env *env, double x, double y)
{
	double		r;
	double		theta;

	r = sqrt (sqrt (x * x + y * y));
	theta = atan2 (y, x) * .5;
	if (random_bit ())
		theta += M_PI;
	env->z.r = r * cos(theta);
	env->z.i = r * sin(theta);
}

/*
** 14 : Bent
*/

void			bent(t_env *env, double x, double y)
{
	if (x >= 0.0 && y >= 0.0)
	{
		env->z.r = x;
		env->z.i = y;
	}
	else if (x < 0.0 && y >= 0.0)
	{
		env->z.r = 2.0 * x;
		env->z.i = y;
	}
	else if (x >= 0.0 && y < 0.0)
	{
		env->z.r = x;
		env->z.i = y * .5;
	}
	else if (x < 0.0 && y < 0.0)
	{
		env->z.r = 2.0 * x;
		env->z.i = y * .5;
	}
}

// /*
// ** 15 : Waves
// */

// void			waves(t_env *env, double x, double y)
// {
// 	env->z.r = x + pa1 * sin (y / (pa2 * pa2));
// 	env->z.i = y + pa3 * sin (x / (pa4 * pa4));
// }

// void			funct(t_env *env, double x, double y)
// { 16/* Fisheye */
// 	r = 2.0 / (1. + sqrt (x * x + y * y));
// 	env->z.r = r * y;
// 	env->z.i = r * x;
// }

// void			funct(t_env *env, double x, double y)
// { 17/* Popcorn */
// 	env->z.r = x + c * sin (tan (3.0 * y));
// 	env->z.i = y + f * sin (tan (3.0 * x));
// }

// void			funct(t_env *env, double x, double y)
// { 18/* Exponential */
// 	env->z.r = exp (x - 1.0) * cos (M_PI * y);
// 	env->z.i = exp (x - 1.0) * sin (M_PI * y);
// }

// void			funct(t_env *env, double x, double y)
// { 19/* Power */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	env->z.r = pow (r, sin (theta)) * cos (theta);
// 	env->z.i = pow (r, sin (theta)) * sin (theta);
// }

// void			funct(t_env *env, double x, double y)
// { 20/* Cosine */
// 	env->z.r = cos (M_PI * x) * cosh (y);
// 	env->z.i = -sin (M_PI * x) * sinh (y);
// }

// void			funct(t_env *env, double x, double y)
// { 21/* Rings */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	prefix = modulus ((r + pa2 * pa2),
// 			 (2.0 * pa2 * pa2)) - (pa2 * pa2) + (r * (1.0 - pa2 * pa2));
// 	env->z.r = prefix * cos (theta);
// 	env->z.i = prefix * sin (theta);
// }
// void			funct(t_env *env, double x, double y){ 22/* Fan */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	t = M_PI * c * c;
// 	if (modulus (theta, t) > (t * .5))
// 		{
// 		  env->z.r = r * cos (theta - (t * .5));
// 		  env->z.i = r * sin (theta - (t * .5));
// 		}
// 	else
// 		{
// 		  env->z.r = r * cos (theta + (t * .5));
// 		  env->z.i = r * sin (theta + (t * .5));
// 		}
// }
// void			funct(t_env *env, double x, double y){ 23/* Eyefish */
// 	r = 2.0 / (1. + sqrt (x * x + y * y));
// 	env->z.r = r * x;
// 	env->z.i = r * y;
// }
// void			funct(t_env *env, double x, double y){ 24/* Bubble */
// 	r = 4 + x * x + y * y;
// 	env->z.r = (4.0 * x) / r;
// 	env->z.i = (4.0 * y) / r;
// }
// void			funct(t_env *env, double x, double y){ 25/* Cylinder */
// 	env->z.r = sin (x);
// 	env->z.i = y;
// }
// void			funct(t_env *env, double x, double y){ 26/* Tangent */
// 	env->z.r = sin (x) / cos (y);
// 	env->z.i = tan (y);
// }
// void			funct(t_env *env, double x, double y){ 27/* Cross */
// 	r = sqrt (1.0 / ((x * x - y * y) * (x * x - y * y)));
// 	env->z.r = x * r;
// 	env->z.i = y * r;
// }
// void			funct(t_env *env, double x, double y){ 28/* Collatz */
// 	env->z.r = .25 * (1.0 + 4.0 * x - (1.0 + 2.0 * x) * cos (M_PI * x));
// 	env->z.i = .25 * (1.0 + 4.0 * y - (1.0 + 2.0 * y) * cos (M_PI * y));
// }
// void			funct(t_env *env, double x, double y){ 29/* Mobius */
// 	t = (pa3 * x + pa4) * (pa3 * x + pa4) + pa3 * y * pa3 * y;
// 	env->z.r =
// 		((pa1 * x + pa2) * (pa3 * x + pa4) + pa1 * pa3 * y * y) / t;
// 	env->z.i =
// 		(pa1 * y * (pa3 * x + pa4) - pa3 * y * (pa1 * x + pa2)) / t;
// }
// void			funct(t_env *env, double x, double y){ 30/* Blob */
// 	r = sqrt (x * x + y * y);
// 	theta = atan2 (y, x);
// 	env->z.r =
// 		r * (pa2 +
// 					0.5 * (pa1 - pa2) * (sin (pa3 * theta) +
// 					  1)) * cos (theta);
// 	env->z.i =
// 		r * (pa2 +
// 					0.5 * (pa1 - pa2) * (sin (pa3 * theta) +
// 					  1)) * sin (theta);
// }
// void			funct(t_env *env, double x, double y){ 31/* Noise */
// 	theta = RANDR (0, 1.);
// 	r = Rt_env *env, double x, double y){ 33/* Square */
// 	env->z.r = RANDR (0, 1.) - 0.5;
// 	env->z.i = RANDR (0, 1.) - 0.5;
// }
// void			funct(t_env *env, double x, double y){ 34/* Not Broken Waves */
// 	env->z.r = x + b * sin (y / pow (c, 2.0));
// 	env->z.i = y + e * sin (x / pow (f, 2.0));
// }
// /*
// **
//*/
void			curl(t_env *env, double x, double y)
{
	static double	p1 = 0.3;
	static double	p2 = -0.7;
	double			t1;
	double			t2;

	t1 = 1 + p1 * x + p2 * (x * x - y * y);
	t2 = p1 * y + 2 * p2 * x * y;
	env->z.r = (1 / (t1 * t1 + t2 * t2)) * (x * t1 + y * t2);
	env->z.i = (1 / (t1 * t1 + t2 * t2)) * (y * t1 - x * t2);
}

t_cplx			cross(t_env *env, double x, double y) // Cross (Variation 48)
{
	double		c;
	t_cplx		z;

	(void)env;
	c = sqrt(pow(x * x - y * y, -2));
    z.r = x * c;
    z.i = y * c;
    return (z);
}