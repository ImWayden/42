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

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == '=' || keycode == 65451)
		env->max_i += 10;
	if (keycode == '-' || keycode == 65453)
		env->max_i -= 10;
	env->max_i = env->max_i < 0 ? 0 : env->max_i;
	return (0);
}

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