/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 03:00:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int				main(int ac, char **av)
{
	t_env		env;

	ft_init(&env, av[ac -1]);
	if ((env.ptr = mlx_init()) == NULL)
		return (0);
	if ((env.win = mlx_new_window(env.ptr, SCREEN_W, SCREEN_H
		, "Raytracer")) == NULL)
		return (0);
	if (!(env.img = mlx_new_image(env.ptr, SCREEN_W, SCREEN_H)))
		exit (0);
	if (!(env.data = mlx_get_data_addr(env.img, &(env.bpp), &(env.sizel)
		, &(env.endian))))
		exit (0);
	mlx_expose_hook(env.win, expose, &env);
	mlx_loop(env.ptr);
	return (0);
}
