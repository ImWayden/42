/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 12:50:24 by msarr             #+#    #+#             */
/*   Updated: 2015/01/26 12:50:24 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	randing(double *a, double *d)
{
	int	i;

	i = 0;
	while (!i || (*a * *a + *d * *d) > 1)
	{
		*a = drand48();
		*d = RANDR(*a * *a, 1);
		if (random_bit())
			*d = -(*d);
		i++;
	}
}

static void	mapping (t_color *color)
{
	double	a;
	double	b;
	double	d;
	double	e;
	double	k;

	a = 0;
	b = 0;
	d = 0;
	e = 0;
	k = 0;
	while (!k || (a * a + b * b + d * d + e * e) > (1 + (a * e - d * b) * (a * e - d * b)))
	{
		randing(&a, &d);
		randing(&b, &e);
		k++;
	}
	color->ac = a;
	color->bc = b;
	color->cc = RANDR (-2, 2);
	color->dc = d;
	color->ec = e;
	color->fc = RANDR (-2, 2);
}

void		hslmap(t_env *env)
{
	env->hslmap[0] = rgbtohsl(env->rgbmap[0]);
	env->hslmap[0].l = 0.2;
	env->hslmap[1] = rgbtohsl(env->rgbmap[1]);
	env->hslmap[1].l = 0.2;
	env->hslmap[2] = rgbtohsl(env->rgbmap[2]);
	env->hslmap[2].l = 0.2;
}

void		rgbmap(t_env *env)
{
	env->rgbmap[0] = Green;
	env->rgbmap[1] = Yellow;
	env->rgbmap[2] = Red;
}

void		colormap(t_env *env)
{
	int		i;
	int		j;

	rgbmap(env);
	hslmap(env);
	if ((env->colormap = malloc(NCOLORS * sizeof(t_color))))
	{
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 3)
			{
				env->hslmap[j].l += 0.8 / 10.0;
				env->colormap[(j * 10) + i] = color(hsltorgb(env->hslmap[j]));
				if (random_bit())
					mapping (&(env->colormap[(j * 10) + i]));
				j++;
			}
			i++;
		}
	}
	else
	{
		ft_putendl("malloc() in pixelmap_init () failed.\n");
		exit (EXIT_FAILURE);
	}
}
