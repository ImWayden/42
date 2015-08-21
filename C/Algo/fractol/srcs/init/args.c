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

static int	fractal(t_env *env, char *str)
{
	if (!ft_strcmp(str, "-m"))
		env->fract = mandel;
	else if (!ft_strcmp(str, "-j"))
		env->fract = julia;
	else if (!ft_strcmp(str, "-b"))
		env->fract = buddha;
	else if (!ft_strcmp(str, "-n"))
		env->fract = newton;
	else if (!ft_strcmp(str, "-bu"))
		env->fract = burningship;
	else
		return (0);
	return (1);
}

static int	treat_args(t_env *env, char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-c"))
			env->back = background(ft_atoi(av[++i]));
		else if (!ft_strcmp(av[i], "-nc"))
			env->nc = ft_atoi(av[++i]);
		else if (!ft_strcmp(av[i], "-p"))
			env->pow = ft_atoi(av[++i]);
		else if (!ft_strcmp(av[i], "-t") && i++)
			env->render = t_render;
		else if (fractal(env, av[i]))
			i++;
		else
			break ;
	}
	return (i - ac);
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
	env->render = sierpinski;
	return (treat_args(env, av, ac));
}
