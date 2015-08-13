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
	data[0] = color.r;
	data[1] = color.g;
	data[2] = color.b;
}

void	plotpixel(t_env *env, int x, int y, t_rgb color)
{
	unsigned int p;

	p = x + y * SCREEN_W;
	p *= 4;
	env->data[p] = ~ (int)(color.r);
	env->data[p + 1] = ~(int)(color.g);
	env->data[p + 2] = ~(int)(color.b);
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
