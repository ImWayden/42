/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 18:33:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int				ft_key_hook(int keycode, t_env * env)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == UP)
	{
		forward(env);
			if (!(env->img = mlx_new_image(env->ptr, SCREEN_W, SCREEN_H)))
		exit (0);
	if (!(env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizel)
		, &(env->endian))))
		exit (0);
		expose(env);
	}
	if (keycode == 65307)
		exit(0);
	return (0);
}

int				ft_mouse_hook(int button, int x, int y)
{
	ft_putstr("mouse : ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(" : ");
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

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
	cam_setup(&env.cam);
	mlx_key_hook(env.win, ft_key_hook, &env);
	mlx_mouse_hook(env.win, ft_mouse_hook, &env);
	mlx_expose_hook(env.win, expose, &env);
	mlx_loop(env.ptr);
	return (0);
}
