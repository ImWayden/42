/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 21:57:30 by msarr             #+#    #+#             */
/*   Updated: 2015/04/16 21:57:30 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				img_init(t_env *env)
{
	int			sizel;
	int			endian;
	int			bpp;

	if (!(env->ptr = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->ptr, SCREEN_W, SCREEN_H, "Fractol")))
		return (0);
	if (!(env->img = mlx_new_image(env->ptr, SCREEN_W, SCREEN_H)))
		return (0);
	if (!(env->data = mlx_get_data_addr(env->img, &bpp, &sizel, &endian)))
		return (0);
	return (1); 
}
