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

static void	coord_init(t_env *env)
{
	env->xres = SCREEN_W;
	env->yres = SCREEN_H;
	env->x_min = -1.0;
	env->x_max = 1.0;
	env->y_min = -1.0;
	env->y_max = 1.0;
	env->ranx = env->x_max - env->x_min;
	env->rany = env->y_max - env->y_min;
	env->zoom_x = SCREEN_W / (env->x_max - env->x_min);
	env->zoom_y = SCREEN_H / (env->y_max - env->y_min);
}

static void	img_init(t_env *env)
{
	if (!(env->ptr = mlx_init())
		||
		!(env->win = mlx_new_window(env->ptr, SCREEN_W, SCREEN_H, "Fractol"))
		||
		!(env->img = mlx_new_image(env->ptr, SCREEN_W, SCREEN_H))
		||
		!(env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizel)
		, &(env->endian))))
	{

		ft_putendl("erro!\n");
		exit(0);
	}
}

void		init(t_env *env, char **av)
{
	/* change default values set in fractal.h */
	coord_init(env);
	env->seed = SEED;
	env->ncolors = NCOLORS;
	env->rgb = IndianRed;
	env->samples = SAMPLES;
	env->gamma = GAMMA;
	env->symmetry = 1;
	env->invert = 0;
	env->max_i = (av[1][1] == 'v') ? ITT : 25;
	env->count = 1;
	env->colormap = NULL;
	env->funct = (av[1][1] == 'v') ? main_flame : main_mandel;
	env->conf =	(av[1][1] == 'j') ? 1 : ft_atoi(av[2]) % 46;
	colormap(env);
	pixelmap(env);
	img_init(env);
}
