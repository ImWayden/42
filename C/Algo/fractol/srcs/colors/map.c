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

void		colormap(t_env *env)
{
	t_hsl	h;
	double	l;
	int		i;

	if ((env->colormap = malloc(NCOLORS * sizeof(t_color))))
	{
		i = 0;
		h = rgbtohsl(env->rgb);
		l = h.l;
		printf("%lf %lf %lf\n", h.h, h.s, l);
		while (i < NCOLORS)
		{
			h.l += (1 - h.l) / NCOLORS;
			printf("newl = %lf ", h.l);
			env->colormap[i] = color(hsltorgb(h));
			if (random_bit())
				mapping (&(env->colormap[i]));
			i++;
		}
	}
	else
	{
		ft_putendl("malloc() in pixelmap_init () failed.\n");
		exit (EXIT_FAILURE);
	}
}


