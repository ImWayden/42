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
void	lotpixel(char *data, t_rgb color)
{
	data[0] = color.b;
	data[1] = color.g;
	data[2] = color.r;
}

void	plotpixel(t_env *env, int x, int y, t_rgb color)
{
	unsigned int p;

	p = x + y * SCREEN_W;
	p *= 4;
	env->data[p] = color.b;
	env->data[p + 1] = color.g;
	env->data[p + 2] = color.r;
}

void	putpixels(t_env *env)
{
	int		x;
	int		y;

	x = -1;
	while (++x < SCREEN_H)
	{
		y = -1;
		while (++y < SCREEN_W)
			if (!(ISBLACK(env->pixels[y][x])))
				plotpixel(env, y, x, env->pixels[y][x]);
	}
}


void	addpixel(t_env *env, int x, int y, t_rgb color)
{
	unsigned int p;

	p = x + y* SCREEN_W;
	p *= 4;
	env->data[p] += env->data[p] ? color.r * 0.5 : color.r;
	env->data[p + 1] += env->data[p + 1] ? color.g * 0.5 : color.g;
	env->data[p + 2] += env->data[p + 2] ? color.b * 0.5 : color.b;
}

t_rgb	getpixel(t_env *env, int x, int y)
{
	unsigned int p;
	t_rgb		color;

	p = x + y* SCREEN_W;
	p *= 4;
	color.r = env->data[p];
	color.g = env->data[p + 1];
	color.b = env->data[p + 2];
	return (color);
}
