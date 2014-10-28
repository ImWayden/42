/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:20:56 by msarr             #+#    #+#             */
/*   Updated: 2014/10/12 00:52:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line(t_env env, t_coord pi, t_coord pf)
{
	double	x;
	double	y;
	double	a;
	double	b;
	int		color;

	if (!pi.z && !pf.z)
		color = 0x7FFF00;
	else if (pi.z != pf.z)
		color = 0x8B4513;
	else
		color = 0xFFFAFA;
	a = (pf.y - pi.y) / (pf.x - pi.x);
	b = pi.y - a * pi.x;
	x = pi.x;
	while (x <= pf.x)
	{
		y = (a * x + b);
		mlx_pixel_put(env.ptr, env.win, x, y, color);
		x += 1;
	}
}

int			fake_expose(t_env *envc)
{
	int		i;
	int		j;
	t_env	env;
	t_coord	**tab;

	env = *envc;
	tab = env.tab;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j].z != -2)
		{
			if (tab[i][j + 1].z != -2)
				line(env, tab[i][j], tab[i][j + 1]);
			if (tab[i + 1])
				line(env, tab[i + 1][j], tab[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
