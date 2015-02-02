/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:57:48 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 14:57:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "colors.h"

void	plotpixel(t_env *env, int x, int y, t_rgb color)
{
	unsigned int p;

	p = x + y* SCREEN_W;
	p *= 4;
	//in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
	env->data[p] = color.b;
	env->data[p + 1] = color.g;
	env->data[p + 2] = color.r;
}

void	addpixel(t_env *env, int x, int y, t_rgb color)
{
	unsigned int p;

	p = x + y* SCREEN_W;
	p *= 4;
	//in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
	env->data[p] += color.r;
	env->data[p + 1] += color.g;
	env->data[p + 2] += color.b;
}

t_rgb	getpixel(t_env *env, int x, int y)
{
	unsigned int p;
	t_rgb		color;

	p = x + y* SCREEN_W;
	p *= 4;
	//in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
	color.r = env->data[p];
	color.g = env->data[p + 1];
	color.b = env->data[p + 2];
	return (color);
}

void		pixelmap(t_env *env)
{
	int 	i;

	if ((env->pixels = malloc(env->yres * sizeof(t_pixel *))))
	{
		i = 0;
		while (i < env->yres)
		{
			env->pixels[i] = malloc (env->xres * sizeof(t_pixel));
			if (env->pixels[i] == NULL)
			{
				ft_putendl("malloc() failed\n");
				exit (EXIT_FAILURE);
			}
			ft_memset (env->pixels[i], '\0', env->xres * sizeof(t_pixel));
			i++;
		}
	}
	else
	{
		ft_putendl("malloc() in pixelmap_init () failed.\n");
		exit (EXIT_FAILURE);
	}
}