/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:25:11 by msarr             #+#    #+#             */
/*   Updated: 2015/02/03 17:25:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fractol.h"
	// 	zn = sqrt(x * x + y * y);
			// 	nu = log(log(zn) / log(2)) / log(2);
			// 	// Rearranging the potential function.
			// 	// Could remove the sqrt and multiply log(zn) by 1/2, but less clear.
			// 	// Dividing log(zn) by log(2) instead of log(N = 1<<8)
			// 	// because we want the entire palette to range from the
			// 	// center to radius 2, NOT our bailout radius.
			// 	i = (int)(i + 1 - nu);
			// 	// i = i - log(log(mod(env->z))) / log(2); // Lisse le dégradé (sorte de formule magique)
			// 	// i = ((env->ncolors - 1) * i) / env->max_i;             // Mise à l'échelle de la palette de couleur*/
			// 	// plotpixel(env, x, y, env->colormap[i].rgb);
			
			// i %= NCOLORS;
			// printf("i = %i\n", i);
			// i = i < 0 ? -i : i;
			// i = floorl(i % 255);
			// printf("i = %i\n", i);
			// color = linear_inter(env->colormap[i].rgb, env->colormap[i + 1].rgb, (double)(i % 1));
double		clamp(double value, double min, double max)
{
	double result;

	result = value;
	if (value > max)
		result = max;
	if (value < min)
		result = min;
	return result;
}

double		dot(t_cplx a, t_cplx b)
{
	double	d;

	d = 0.0;
	d += (a.r * b.r);
	d += (a.i * b.i);
	return (d);
}


t_rgb		style1(t_env *env, t_rgb color)
{
	if (env->z.r > 0 && env->z.i > 0)
		color = Green;
	else if (env->z.r < 0 && env->z.i < 0)
		color = Yellow;
	else
		color = Red;
	return (color);
}


t_rgb		style2(t_env *env, t_rgb color, int i)
{
	double co;
	double co2;
	double fac;
	t_rgb2	c;

	(void)env;
	co = (double)i + 1.0 - log2(0.5 * log2(dot(env->z, env->z)));
	co = sqrt(co / 256.0);
	co2 = env->dist * Divider;
	//co += co2;
	fac = clamp(1.0 / pow(co2, Power), 0.0, 1.0);
	c.r = (.5 + .5 * cos(6.2831 * co + (double)color.r)) * fac * 255.0;
	c.g = (.5 + .5 * cos(6.2831 * co + (double)color.g)) * fac * 255.0;
	c.b = (.5 + .5 * cos(6.2831 * co + (double)color.b)) * fac * 255.0;
	printf("%lf %lf %lf \n", c.r, c.g, c.b);
	return (rgb((int)c.r, (int)c.g, (int)c.b));
}

double		 arg(t_cplx c)
{
	return atan2(c.r, c.i);
}

t_rgb			orbittrap(t_env *env)
{
	double		r;

	r = log(dot(env->z, env->z)) / 4.0 / log(M_PI) - arg(env->z) / 2.0 * M_PI + env->p;
	r = abs(r - round(r));
	printf("%lf _ ", r);
	if (r > 2 || r < 0)
		r = 0.0;
	else
		r = 1.0 - (r / 2.0);
	printf("%lf\n", r);
	return (env->colormap[(int)(r * 18.0) % NCOLORS].rgb);
}