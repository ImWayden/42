/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intervals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:05:17 by msarr             #+#    #+#             */
/*   Updated: 2015/02/02 02:05:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		intervals(t_env *env, char **av, int i)
{
	int 	j;

	if (av[i][1] == 'm' || av[i][1] == 'j')
		j = 1;
	else
		j = 0;
	env->y_min = -1.0;
	env->y_max = 1.0;
	env->x_min = (j == 1) ? -2.0 : -1.0;
	env->x_max = (j == 1) ? 2.0 : 1.0;
	env->max_i = !j ? ITT : (av[i][1] == 'm' ? 150 : 25);
	env->conf =	(av[i][1] == 'j') ? 1 : ft_atoi(av[i + 1]) % 46;
	env->funct = (av[i][1] == 'v') ? main_flame : ((av[i][1] == 'i') ? main_attract : main_mandel);
}