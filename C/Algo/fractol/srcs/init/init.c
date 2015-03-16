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

void		cleanpixels(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < SCREEN_W)
	{
		y = 0;
		while (y < SCREEN_H)
		{
			env->pixels[x][y] = rgb(0, 0, 0);
			y++;
		}
		x++;
	}
}


void		init(t_env *env, char **av)
{
	pthread_mutex_init(&env->mutex, NULL);
	env->back = malloc(SCREEN_H * SCREEN_W * sizeof(t_cplx));
	env->t = malloc(SCREEN_H * SCREEN_W * sizeof(t_thread));
	env->nc = 3;
	env->count = 1;
	env->xres = SCREEN_W;
	env->yres = SCREEN_H;
	env->zoom_factor = 0.25;
	if (!ft_strcmp(av[1], "-m"))
		imandel(env);
	else if (!ft_strcmp(av[1], "-j"))
		ijulia(env);
	else
		exit(0);
	env->zoom_x = SCREEN_W / (env->x_max - env->x_min);
	env->zoom_y = SCREEN_H / (env->y_max - env->y_min);
	rgbmap(env);
	cleanpixels(env);
	env->coeff = coeff();
	img_init(env);	
}
