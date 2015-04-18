/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:56:52 by msarr             #+#    #+#             */
/*   Updated: 2015/04/18 15:56:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_hook(t_env *env)
{
	if (!pthread_mutex_trylock(&env->lock))
	{
		mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
		pthread_mutex_unlock(&env->lock);
	}
	return (0);
}