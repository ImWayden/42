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

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
        init(&env, av);
		env.funct(&env);
		mlx_key_hook(env.win, key_hook, &env);
        mlx_hook(env.win, ButtonRelease, ButtonReleaseMask, mouse_release, &env);
        mlx_hook(env.win, ButtonPress, ButtonPressMask, mouse_press, &env);
        //mlx_hook(env.win, MotionNotify, PointerMotionMask, mouse_hook, &env);
        mlx_expose_hook(env.win, expose, &env);
        mlx_loop(env.ptr);
	}
	return (0);
}