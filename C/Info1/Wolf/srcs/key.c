/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:16:19 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 22:16:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void 			ft_exit(t_env *env, char *str)
{
	// ft_memdel((void **)&env->color);
	// ft_memdel((void **)&env->pixel);
	// ft_memdel((void **)&env->coeff);
	// ft_memdel((void **)&env->t);
	// ft_putstr("Fractol : ");
	(void)env;
	ft_putendl(str);
	exit(0);
}

int					ft_key_press(int keycode, t_env *env)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == UP)
		env->forward = 1;
	if (keycode == DOWN)
		env->back = 1;
	if (keycode == LEFT)
		env->left = 1;
	if (keycode == RIGHT)
		env->right = 1;
	if (keycode == 53)
		ft_exit(env, "See ya.");
	return (0);
}

int					ft_key_release(int keycode, t_env *env)
{
	if (keycode == UP)
		env->forward = 0;
	if (keycode == DOWN)
		env->back = 0;
	if (keycode == LEFT)
		env->left = 0;
	if (keycode == RIGHT)
		env->right = 0;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int					ft_key_hook(t_env *env)
{
	static double	movespeed = 0.005;
	static double	rotspeed = 0.005;

	if (env->forward)
		forward(env, movespeed);
	if (env->back)
		back(env, movespeed);
	if (env->right)
		turn_right(env, rotspeed);
	if (env->left)
		turn_left(env, rotspeed);
	raycaster(env);
	return (0);
}
