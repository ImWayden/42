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
		color = COLOR_WHITE;
	else if (pi.z != pf.z)
		color = COLOR_RED;
	else
		color = COLOR_GREEN;
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

void		line2(t_env env, t_coord pi, t_coord pf)
{
	double	y;
	int		color;

	if (!pi.z && !pf.z)
		color = 0x7FFF00;
	else if (pi.z != pf.z)
		color = 0x8B4513;
	else
		color = 0xFFFAFA;
	if (pi.y < pf.y)
		y = pi.y;
	else
		y = pf.y;
	while (y < (pf.y < pi.y ? pi.y : pf.y))
	{
		mlx_pixel_put(env.ptr, env.win, pi.x, y, color);
		y += 1;
	}
}

void		draw_lem(t_env *env, t_room **room)
{
	int		i;
	int		x;
	int		y;
	t_coord	pf;
	t_coord	pi;
	t_link	*l;
	t_room	*r;

	i = 0;
	while (i < 1000)
	{
		if (room[i] && room[i]->dist < 10000 && room[i]->dist > 0)
		{
			x = room[i]->x;
			y = room[i]->y;
			room[i]->z = room[i]->dist * 5;
			room[i]->x = env->pad * 0.71 * (x - y) + env->x * env->pad;
			room[i]->y = env->pad * (-0.82 * room[i]->z + 0.41 * (x + y)) + env->y * 5;
			pf.x = room[i]->x;
			pf.y = room[i]->y;
			pf.z = room[i]->z;
			pi = env->tab[y][x];
			line(*env, pi, pf);
		}
		i++;
	}
	i = 0;
	while (i < 1000)
	{
		if (room[i])
		{
			pf.x = room[i]->x;
			pf.y = room[i]->y;
			pf.z = room[i]->z;
			l = room[i]->lst;
			while (l)
			{
				r = l->room;
				if (r->dist < 10000)
				{
					if (r->dist == 0)
						pi = env->tab[env->e_y][env->e_x];
					else
					{
						pi.x = r->x;
						pi.y = r->y;
						pi.z = r->z;
					}
					line(*env, pi, pf);
				}
				l = l->next;
			}
		}
		i++;
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
	draw_lem(envc, envc->room);
	return (0);
}
