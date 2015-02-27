/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intervals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:05:17 by msarr             #+#    #+#             */
/*   Updated: 2015/02/02 02:05:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel_init(t_env *env)
{
	env->y_min = -2.0;
	env->y_max = 2.0;
	env->x_min = -2.0;
	env->x_max = 2.0;
	env->max_i = 150;
	env->conf =	0;
	env->main = mandelbrot;
	env->samples = SCREEN_H;
}

void		julia_init(t_env *env)
{
	env->y_min = -2.0;
	env->y_max = 2.0;
	env->x_min = -2.0;
	env->x_max = 2.0;
	env->max_i = 50;
	env->conf =	1;
	env->main = mandelbrot;
	env->samples = SCREEN_H;
}

void		flame_init(t_env *env, char *av)
{
	env->y_min = -1.0;
	env->y_max = 1.0;
	env->x_min = -1.0;
	env->x_max = 1.0;
	env->max_i = ITT;
	env->conf =	ft_atoi(av);
	env->main = flame;
	env->samples = SAMPLES;
}
