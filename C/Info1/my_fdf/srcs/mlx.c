/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:20:56 by msarr             #+#    #+#             */
/*   Updated: 2014/10/10 19:20:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fake_expose(t_env env)
{
	int			i;
	int			j;
	t_coord		**tab;

	tab = env.tab;
	i = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j].z != -1)
		{
			mlx_pixel_put(env.ptr, env.win, tab[i][j].x, tab[i][j].y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
