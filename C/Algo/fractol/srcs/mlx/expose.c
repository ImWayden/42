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

	row = 0;
	while (env->funct == main_flame && row < env->yres)
	{
		for (col = 0; col < env->xres; col++)
		{
			plotpixel(env, col, row, env->pixels[row][col].rgb);
		}
		row++;
    }
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}