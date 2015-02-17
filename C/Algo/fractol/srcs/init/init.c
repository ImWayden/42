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
	int i = 1;
	env->xres = SCREEN_W;
	env->yres = SCREEN_H;
	env->left = 0;
	env->right = 0;
	env->y_min = -2.0;
	env->y_max = 2.0;
	env->x_min = -2.0;
	env->x_max = 2.0;
	env->ranx = env->x_max - env->x_min;
	env->rany = env->y_max - env->y_min;
	env->zoom_x = SCREEN_W / env->ranx;
	env->zoom_y = SCREEN_H / env->rany;
	env->max_i = av[i][1] == 'm' ? 150 : 25;
	env->max_i = av[i][1] == 'v' ? ITT : env->max_i;
	env->conf =	av[i][1] == 'j' ? 1 : ft_atoi(av[i + 1]) % 46;
	env->funct = av[i][1] == 'v' ? main_flame : env->funct;
	env->funct = av[i][1] == 'm' ? main_mandel : env->funct;
	// env->seed = SEED;
	env->ncolors = NCOLORS;
	env->samples = SAMPLES;
	env->symmetry = 1;
	env->invert = 0;
	env->count = 1;
	colormap(env);
	pixelmap(env);
	img_init(env);
}
