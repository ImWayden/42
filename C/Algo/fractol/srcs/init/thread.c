/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 22:39:03 by msarr             #+#    #+#             */
/*   Updated: 2015/03/07 22:39:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_thread		*threadmap(t_env *env)
{
	t_thread	*thread;
	int			y;
	int			d;

	thread = NULL;
	d = SCREEN_H;
	if ((thread = malloc(d * sizeof(t_thread))))
	{
		y = -1;
		while (++y < SCREEN_H)
		{
			thread[y].y = y;
			thread[y].x = -1;
			thread[y].env = env;
		}
	}
	return (thread);
}
