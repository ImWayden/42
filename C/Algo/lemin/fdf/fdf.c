/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/12/06 04:33:41 by msarr            ###   ########.fr       */
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

void			clean(t_env env)
{
	int			i = 0;
	int			j = 0;	
	int			in;

	while (i < env.w)
	{
		j = 0;
		while (j < env.h)
		{
			in = (env.bpp >> 3)* ((j * (env.sizel >> 2)) + i);
			env.data[in] = 0;
			env.data[in + 1] = 0;
			env.data[in + 2] = 0;
			j++;
		}
		i++;
	}
}

int				fdf(t_env env)
{
	//mlx_key_hook(env.win, ft_key_hook, &env);
	//mlx_mouse_hook(env.win, ft_mouse_hook, &env);
	//fake_expose(&env);
	//mlx_loop(env.ptr);
	//project(envc, envc->room);
	(void)env;
	return (EXIT_SUCCESS);
}
