/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/27 21:59:15 by sraccah          ###   ########.fr       */
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

	env.i = -1;
	env.j = 0;
	env.count = 0;
	env.k = env.nbr_col;
	while (ac == 2)
	{
		ft_nbr_line_col(av[1], &env);
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
