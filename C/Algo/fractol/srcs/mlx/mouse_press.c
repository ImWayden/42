/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:57:37 by msarr             #+#    #+#             */
/*   Updated: 2015/04/18 15:57:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_env *env)
{
	double	pointx;
	double	pointy;

	if (button == 5  || button == 4)
	{
		pointx = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
		pointy = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		if (button == 4)
			env->zoom *= ZOOM_FACTOR;
		if (button == 5)
			env->zoom /= ZOOM_FACTOR;
		env->ptx = pointx - (double) ((x - (SCREEN_W / 2.0)) / env->zoom);
		env->pty = pointy - (double) ((y - (SCREEN_H / 2.0)) / env->zoom);
		env->max_i = (SCREEN_W / 2) * 0.049715909 * log10(env->zoom);
	printf("Fractol : iter :  %lu, zoom : %Lf\n", env->max_i, env->zoom);
		
	}
	return 0;
}