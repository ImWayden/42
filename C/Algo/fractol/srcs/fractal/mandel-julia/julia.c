/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 19:09:17 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 19:09:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_env *env, int x, int y)
{
	static  int i = -1;

	if (!x && !y)
		i++;
	env->c = conf(i);
	env->z.r = (double)x / env->zoom_x + env->x_min;
	env->z.i = -((double)y / env->zoom_y + env->y_min);
}