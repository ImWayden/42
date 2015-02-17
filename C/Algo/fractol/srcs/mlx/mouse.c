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

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_env *env)
{
	ft_putnbr(button);
	env->z.r = (double)x / env->zoom_x + env->x_min;
	env->z.i = env->y_max - (double)y / env->zoom_y;
	if (button == 1)
	{
		env->zoom_x *= 2;
		env->zoom_y *= 2;
		ft_putendl("i am zooming");
	}
	if (button == 2)
	{
		env->zoom_x -= 2;
		env->zoom_y -= 2;
		ft_putendl("i am dezooming");
	}
	env->ranx = SCREEN_W / env->zoom_x;
	env->rany = SCREEN_H / env->zoom_y;
	env->y_min = env->z.i - env->rany / 2.0;
	env->y_max = env->z.i + env->rany / 2.0;
	env->x_min = env->z.r - env->ranx / 2.0;
	env->x_max = env->z.r + env->ranx / 2.0;
	env->funct(env);
	return 0;
}

int		mouse_release(int button, int x, int y, t_env *env)
{
	printf("%i %i %i\n", button, x, y);
	if (button == 1)
		env->left = 0;
	if (button == 2)
		env->right = 0;
	(void)y;
	(void)x;
	return (0);
}

int		mouse_hook(int x, int y, t_env *env)
{
	(void)y;
	(void)x;
	if (env->funct == main_mandel && env->conf)
		env->conf = (env->conf + 1) % 42;
	env->funct(env);
	return (0);
}
