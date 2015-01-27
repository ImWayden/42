/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:47:46 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 14:47:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	return (0);
}

int					mouse_button(int button, int x, int y, t_env *env)
{main_mandel(env);

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

int				mouse_move(int x, int y, t_env *env)
{
	(void)env;
	ft_putstr("mouse : ");
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(" ok: ");
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

int				main(int ac, char **av)
{
	t_env		env;

	if (ac == 2)
	{
		(void)av;
		env.seed = SEED;
		srandom (4);
		srand48 (random ());
		init(&env);
		main_flame(&env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_mouse_hook(env.win, mouse_button, &env);
		mlx_expose_hook(env.win, expose, &env);
		mlx_hook(env.win, MotionNotify, PointerMotionMask, mouse_move, &env);
		mlx_loop(env.ptr);
	}
	return (0);
}