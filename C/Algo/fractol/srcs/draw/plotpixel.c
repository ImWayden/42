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

void	plotpixel(t_env *env, int x, int y, t_rgb color)
{
	unsigned int p;

	p = x + y* SCREEN_W;
	p *= 4;
	//in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
	env->data[p] = color.r;
	env->data[p + 1] = color.g;
	env->data[p + 2] = color.b;
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