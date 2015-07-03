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
	if (button == 5  || button == 4)
	{
		gettimeofday(&(env->end), NULL);
		if ((env->end.tv_usec - env->start.tv_usec) > 10000)
		{
			env->ptx = env->ptx + ((x - (SCREEN_W / 2)) / env->zoom);
			env->pty = env->pty + ((y - (SCREEN_H / 2)) / env->zoom);
		}
		if (button == 4)
			env->zoom *= ZOOM_FACTOR;
		if (button == 5)
			env->zoom /= ZOOM_FACTOR;
		env->max_i = (SCREEN_W / 2) * 0.049715909 * log10(env->zoom);
		gettimeofday(&(env->start), NULL);
		render((void *)env);
	}
	return 0;
}