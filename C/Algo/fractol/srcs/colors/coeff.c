/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
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
	do
	{
		ft_putendl("randing");
		*a = drand48();
		*d = RANDR(*a * *a, 1);
		if (random_bit())
			*d = -(*d);
	}
	while ((*a * *a + *d * *d) > 1);
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
		ft_putendl("ok");
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

void		map(t_env *env)
{
	int 	i;

	i= -1;
	env->pixels = malloc (env->yres * sizeof (t_pixel *));
	if (env->pixels == NULL)
    {
      printf ("malloc() in buffer_init () failed.\n");
      exit (EXIT_FAILURE);
    }
    for (i = 0; i < env->yres; i++)
    {
    	env->pixels[i] = malloc (env->xres * sizeof(t_pixel));
    	if (env->pixels[i] == NULL)
    	{
    		printf ("malloc() failed\n");
    		exit (EXIT_FAILURE);
    	}
    	memset (env->pixels[i], '\0', env->xres * sizeof (t_pixel));
    }
	env->colormap = malloc(env->ncolors * sizeof(t_color));
	if (!env->colormap)
		exit (EXIT_FAILURE);
	i = 0;
	while (i < env->ncolors)
	{
		env->colormap[i] = color();
		if (random_bit())
			mapping (&(env->colormap[i]));
		ft_putnbr(i);
		ft_putchar('\n');
		i++;
	}
}
