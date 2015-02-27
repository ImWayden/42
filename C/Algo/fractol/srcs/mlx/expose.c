/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:36:15 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 15:36:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     expose(t_env *env)
{
	int		i;

	i = 0;
	zoom(env);
	while (i < 100)
	{
		if (0 != pthread_create(&env->threadtab[i].thread, NULL, env->main, (void *)&env->threadtab[i]))
			exit (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < 100)
	{
		if (pthread_join(env->threadtab[i].thread, NULL))
			exit(0);
		i++;
	}
	return (0);
}