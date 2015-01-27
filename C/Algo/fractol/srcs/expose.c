/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:36:15 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 15:36:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     expose(t_env *env)
{
	int row, col;
	for (row = 0; row < env->yres; row++)
	{
		for (col = 0; col < env->xres; col++)
		{
			env->data[(col + row * env->xres) * 4] = env->invert == 1 ? ~(env->pixels[row][col].r) :
	    env->pixels[row][col].r;
	  env->data[(col + row * env->xres) * 4 + 1] =
	    env->invert ==
	    1 ? ~(env->pixels[row][col].
		  g) : env->pixels[row][col].g;
	  env->data[(col + row * env->xres) * 4 + 2] =
	    env->invert ==
	    1 ? ~(env->pixels[row][col].
		  b) : env->pixels[row][col].b;
	}
    }
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}