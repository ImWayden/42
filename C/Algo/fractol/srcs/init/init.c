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

/* allocate memory for the image buffer */
static void	img_init (t_env *env)
{
	env->ranx = env->x_max - env->x_min;
	env->rany = env->y_max - env->y_min;

	/* malloc new memory array for the image */
	if (!(env->ptr = mlx_init()))
		exit(0);
	if (!(env->win = mlx_new_window(env->ptr, SCREEN_W, SCREEN_H
		, "Fractol")))
		exit(0);
	if (!(env->img = mlx_new_image(env->ptr, SCREEN_W, SCREEN_H)))
		exit(0);
	if (!(env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizel)
		, &(env->endian))))
		exit(0);
	ft_putendl("Done!\n");
}

void		init(t_env *env)
{
	/* change default values set in fractal.h */
	env->xres = SCREEN_W;
	env->yres = SCREEN_H;
	/*env->x_max = XMAX;
	env->y_max = YMAX;
	env->x_min = XMIN;
	env->y_min = YMIN;*/
	env->x_min = -1.777;
	env->x_max = 1.777;
	env->y_min = -1.0;
	env->y_max = 1.0;
	env->ncolors = NUMV;
	env->samples = SAMPLES;
	env->gamma = GAMMA;
	env->symmetry = 1;
	env->invert = 0;
	env->max_i = ITT;
	env->count = 1;
	env->colormap = NULL;
	env->choice = 0;
	env->conf = 2;
	map(env);
	int i;
	for (i = 0; i < env->ncolors; i++)
    {
      printf ("%f %f %f %f %f %f\n",
	      env->colormap[i].ac,
	      env->colormap[i].bc,
	      env->colormap[i].cc,
	      env->colormap[i].dc,
	      env->colormap[i].ec, env->colormap[i].fc);
    }
	env->zoom_x = SCREEN_W / (env->x_max - env->x_min);
	env->zoom_y = SCREEN_H / (env->y_max - env->y_min);
	img_init(env);
}
