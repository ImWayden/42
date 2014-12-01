/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/29 12:26:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

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

void			ft_init(t_env *env)
{
	set_pos(&env->light.vect, 64, 128, -128);
	set_color(&env->light.color, 255,255,255);
	setintensity(env, 100);
	set_pos(&env->sphere1.vect, 128,128,0);
	set_color(&env->sphere1.color,0,0,255);
	set_radius(&env->sphere1, 50);
	set_color(&env->sphere2.color,255,255,255);
	set_radius(&env->sphere2, 60);
}


int				main()
{
	t_env		env;

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
	ft_init(&env);
	mlx_expose_hook(env.win, raytracer, &env);
	mlx_mouse_hook(env.win, ft_mouse_hook, &env);
	//mlx_loop_hook(env.ptr, ft_key_hook, &env);
	mlx_loop(env.ptr);
	return (0);
}
