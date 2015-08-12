/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 22:01:52 by msarr             #+#    #+#             */
/*   Updated: 2015/04/16 22:01:52 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	treat_args(t_env *env, char **av, int ac)
{
	while (--ac)
	{
		if (!ft_strcmp(av[ac], "-m"))
			env->fract = mandel;
		else if (!ft_strcmp(av[ac], "-j"))
			env->fract = julia;
		else if (!ft_strcmp(av[ac], "-b"))
			env->fract = buddha;
		else if (!ft_strcmp(av[ac], "-n"))
			env->fract = newton;
		else if (!ft_strcmp(av[ac], "-bu"))
			env->fract = burningship;
		else if (!ft_strcmp(av[ac - 1], "-c"))
			env->back = background(ft_atoi(av[ac--]));
		else if (!ft_strcmp(av[ac - 1], "-nc"))
			env->nc = ft_atoi(av[ac--]);
		else if (!ft_strcmp(av[ac - 1], "-p"))
			env->pow = ft_atoi(av[ac--]);
		else if (!ft_strcmp(av[ac], "-t"))
			env->render = t_render;
		else
			break ;
	}
	return (ac);
}

int 		init_args(t_env *env, char **av, int ac)
{
	env->zoom = SCREEN_W * 0.25296875f;
	env->pow = 2.0;
	env->ptx = -0.0;
	env->pty = 0.0;
	env->max_i = (SCREEN_W / 2) * 0.049715909 * log10(env->zoom);
	env->back = curl;
	env->c.r = 0.0;
	env->c.i = 0.0;
	env->render = render;
	return (treat_args(env, av, ac));
}
