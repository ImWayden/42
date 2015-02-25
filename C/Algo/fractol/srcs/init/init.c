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
	int i = 0;
	int j = 0;

	env->samples = av[1][1] == 'm' ? SCREEN_H : SAMPLES;
	env->funct = av[1][1] == 'm' ? mandelbrot : flame;
	env->xres = SCREEN_W;
	env->yres = SCREEN_H;
	while (i < 100)
	{
		env->threadtab[i].y_min = j;
		j += env->samples / 100;
		if (i == 99)
			j = env->samples;
		env->threadtab[i].y_max = j;
		env->threadtab[i].env = env;
		printf("%i %i\n", env->threadtab[i].y_max, env->threadtab[i].y_min);
		i++;
	}
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
	env->max_i = av[1][1] == 'm' ? 150 : 25;
	env->max_i = av[1][1] == 'v' ? ITT : env->max_i;
	env->conf =	av[1][1] == 'j' ? 1 : ft_atoi(av[2]) % 46;
	// env->seed = SEED;
	env->ncolors = NCOLORS;
	env->symmetry = 0;
	env->invert = 0;
	env->count = 1;
	env->left = 0;
	env->zoom_factor = 0.025;
	ft_putendl("ok");
	colormap(env);
	pixelmap(env);
	img_init(env);	
}
