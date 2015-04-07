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

static int		img_init(t_env *env)
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

static int init_args(t_env *env, char **av, int ac)
{
	env->color = NULL;
	env->pixel = NULL;
	env->coeff = NULL;
	env->t = NULL;
	env->zoom = SCREEN_W * 0.25296875f;
	env->ptx = -0.5;
	env->pty = 0.0;
	env->max_i = (SCREEN_W / 2) * 0.049715909 * log10(env->zoom);
	while (--ac)
	{
		ft_putendl(av[ac]);
		if (!ft_strcmp(av[ac], "-m"))
			env->fract = mandel;
		else if (!ft_strcmp(av[ac], "-j"))
			env->fract = julia;
		else if (!ft_strcmp(av[ac], "-b"))
			env->fract = buddha;
		else if (!ft_strcmp(av[ac - 1], "-c"))
			env->back = background(ft_atoi(av[ac--]));
		else
		{
			ft_putendl(av[ac]);
			break ;
		}
	}
	return (ac);
}



void		init(t_env *env, char **av, int ac)
{
	if ((init_args(env, av, ac)))
		ft_exit(env, NULL);
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
	ft_putendl("OK);");
}
