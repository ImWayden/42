/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 01:51:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_key_hook(int keycode)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
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

	while (ac == 2)
	{
		env.file = av[1];
		init(&env);
		if ((env.ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((env.win = mlx_new_window(env.ptr, 640, 480, "fdf")) == NULL)
			return (EXIT_FAILURE);
		mlx_key_hook(env.win, ft_key_hook, &env);
		mlx_mouse_hook(env.win, ft_mouse_hook, &env);
		fake_expose(env);
		mlx_loop(env.ptr);
	}
	return (EXIT_SUCCESS);
}
