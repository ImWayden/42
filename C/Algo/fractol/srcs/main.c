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



int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
        init(&env, av);
        mlx_key_hook(env.win, key_hook, &env);
        mlx_hook(env.win, ButtonPress, ButtonPressMask, mouse_press, &env);
       	mlx_hook(env.win, MotionNotify, PointerMotionMask, mouse_motion, &env);
        mlx_loop_hook(env.ptr, loop_hook, &env);
        mlx_loop(env.ptr);
	}
	return (0);
}