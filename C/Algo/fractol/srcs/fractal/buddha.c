/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 20:22:15 by msarr             #+#    #+#             */
/*   Updated: 2015/03/13 20:22:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixels(t_env *env, int y)
{
	int		x;
	int		d;

	x = -1;
	while (++x < SCREEN_H)
	{
		d = x + y * SCREEN_W;
		if (!ISBLACK(env->pixel[d]))
			plotpixel(env, x, y, env->pixel[d]);
	}
}

void	addred(t_env *env, t_cplx *z, int n)
{
	int		x;
	int		y;
	int		i;
	int		d;

	i = -1;
	while (++i < n)
	{
		x = ((z[i].r - env->ptx) * env->zoom) + (SCREEN_W / 2);
		y = ((z[i].i - env->pty) * env->zoom) + (SCREEN_H / 2);
		if (x > 0 && y > 0 && x < SCREEN_W && y < SCREEN_H)
		{
			d = x + y * SCREEN_W;
			if (n < 115)
				env->pixel[d].r++;
			if (n < 30)
				env->pixel[d].g++;
			if (n < 20)
				env->pixel[d].b++;
		}
	}
}

void		*buddha(void *ptr)
{
	t_env	*env;
	int		x;
	int		y;
	size_t	i;
	t_cplx	 z;
	t_cplx	 zt[ITT];
	t_cplx	 c;
	t_cplx	 a;

	getarg(ptr, &env, &x, &y);
	env->max_i = ITT;
	while (++x < SCREEN_W)
	{
		i = -1;
		while (++i < env->max_i)
			zt[i] = cplx(0.0, 0.0);
		c.r = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		c.i = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		a = cplx(c.r, c.i);
		z = cplx(0.0, 0.0);
		i = -1;
		while (mod(z) < 4 && ++i < env->max_i)
		{
			z = cplx_add(cplx_mult(z, z), c);
			zt[i] = cplx(z.r, z.i);
		}
			a = curl(env->coeff[i % NCOEFF], a.r, a.i);
		plotpixel(env, x, y, lerp(c));
		if (i < env->max_i)
			addred(env, zt, i);
		putpixels(env, y);
	}
	return (NULL);
}