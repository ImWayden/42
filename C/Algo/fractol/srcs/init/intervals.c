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
	env->y_min = -2.0;
	env->y_max = 2.0;
	env->x_min = -2.0;
	env->x_max = 2.0;
	env->max_i = av[i][1] == 'm' ? 150 : 25;
	env->max_i = av[i][1] == 'v' ? ITT : env->max_i;
	env->conf =	av[i][1] == 'j' ? 1 : ft_atoi(av[i + 1]) % 46;
	env->funct = av[i][1] == 'v' ? main_flame : env->funct;
	env->funct = av[i][1] == 'm' ? main_attract : env->funct;
}