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

void		imandel(t_env *env)
{
	env->x_min = -2.1;
	env->x_max = 0.6;
	env->y_min = -1.2;
	env->y_max = 1.2;
	env->max_i = 50;
	env->conf =	0;
	env->fract = mandel;
}

void		ijulia(t_env *env)
{
	env->x_min = -1.0;
	env->x_max = 1.0;
	env->y_min = -1.2;
	env->y_max = 1.2;
	env->max_i = 150;
	env->conf =	1;
	env->fract = julia;
}
