/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:57:52 by msarr             #+#    #+#             */
/*   Updated: 2015/04/18 15:57:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, t_env *env)
{
	if (env->fract == julia)
	{
		env->c.i -= 0.05;
		if (env->c.i < -1)
		{
			env->c.i = 1;
			env->c.r -= 0.05;
		}
		if (env->c.r < -1)
			env->c.r = 1;
		
		//render(env);
		//mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	}
	(void)x;
	(void)y;
	(void)env;
	return (0);
}