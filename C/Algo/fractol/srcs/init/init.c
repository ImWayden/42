/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:45 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 14:46:45 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(t_env *env, char **av, int ac)
{
	env->color = NULL;
	env->pixel = NULL;
	env->coeff = NULL;
	env->t = NULL;
	env->fract = NULL;
	if ((init_args(env, av, ac)))
		ft_exit(env, "Wrong arg !");
	if (!(img_init(env)))
		ft_exit(env, "Unable to init mlx.");
	if (!(env->color = rgbmap()))
		ft_exit(env, "Unable to creat rgbmap");
	if (!(env->pixel = pixelmap()))
		ft_exit(env, "Unable to create pixelmap");
	if (!(env->coeff = coeffmap()))
		ft_exit(env, "Unable to create coeffmap");
	if (!(env->t = threadmap(env)))
		ft_exit(env, "Unable to create threadmap");
}
