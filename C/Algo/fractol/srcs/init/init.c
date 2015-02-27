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

void		threadmap(t_env *env)
{
	int i = 0;
	int j = 0;

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
}

void		init(t_env *env, char **av)
{
	env->ncolors = NCOLORS;
	env->symmetry = 1;
	env->count = 1;
	env->invert = 0;
	env->xres = SCREEN_W;
	env->yres = SCREEN_H;
	env->count = 1;
	env->zoom_factor = 0.25;
	if (!ft_strcmp(av[1], "-m"))
		mandel_init(env);
	else if (!ft_strcmp(av[1], "-j"))
		julia_init(env);
	else if (!ft_strcmp(av[1], "-f"))
		flame_init(env, av[2]);
	env->zoom_x = SCREEN_W / (env->x_max - env->x_min);
	env->zoom_y = SCREEN_H / (env->y_max - env->y_min);
	threadmap(env);
	colormap(env);
	pixelmap(env);
	img_init(env);	
}
