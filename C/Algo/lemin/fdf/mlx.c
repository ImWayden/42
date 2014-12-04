/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:20:56 by msarr             #+#    #+#             */
/*   Updated: 2014/12/03 20:55:14 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				color(int i)
{
	int			tab[10];

	tab[0] = COLOR_WHITE;
	tab[1] = COLOR_RED;
	tab[2] = COLOR_YELLOW;
	tab[3] = COLOR_BLUE;
	return (tab[i]);
}

t_coord	point(t_coord c, int x, int y, int i)
{
	if (i == 0)
		return (new_coord(c.x + x, c.y + y));
	else if (i == 1)
		return (new_coord(c.x + y, c.y + x));
	else if (i == 2)
		return (new_coord(c.x - x, c.y + y));
	else if (i == 3)
		return (new_coord(c.x - y, c.y + x));
	else if (i == 4)
		return (new_coord(c.x + x, c.y - y));
	else if (i == 5)
		return (new_coord(c.x + y, c.y - x));
	else if (i == 6)
		return (new_coord(c.x - x, c.y - y));
	else
		return (new_coord(c.x - y, c.y - x));
}

void	 cercle(t_env env, t_coord c, t_coord s, t_coord e, int flag)
{
	t_coord p;
	int		r = sqrt(SQUARE(c.x - s.x) + SQUARE(c.y - s.y));
	int x = 0;
	int i = 0;
	int y = r;
	int d = r - 1;
 
	while(y >= x)
	{
		i = 0;
		while (i < 8)
		{
			p = point(c, x, y, i);
			if (!flag)
				mlx_pixel_put(env.ptr, env.win, p.x, p.y, env.c);
			else if (p.y >= s.y && p.y >= e.y && flag == 1)
				mlx_pixel_put(env.ptr, env.win, p.x, p.y, env.c);
			else if (p.y <= s.y && p.y <= e.y && flag == -1)
				mlx_pixel_put(env.ptr, env.win, p.x, p.y, env.c);
			i++;
		}
		if (d >= 2*x)
		{
			d -= 2*x + 1;
			x ++;
		}
		else if (d < 2 * (r-y))
		{
			d += 2*y - 1;
			y --;
		}
		else
		{
			d += 2*(y - x - 1);
			y --;
			x ++;
		}
	}
}

void		project(t_env *env, t_room **room)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 1000)
	{
		if (room[i] && room[i]->dist < 10000)
		{
			x = room[i]->x;
			y = room[i]->y;
			room[i]->z = room[i]->dist * 5;
			room[i]->x = env->pad * 0.71 * (x - y) + env->x * env->pad;
			room[i]->y = env->pad * (-0.82 * room[i]->z + 0.41 * (x + y)) + env->y * 5;
		}
		i++;
	}
}

void		draw_s(t_env *env, t_room r, int s)
{
	t_coord	pf;
	t_coord	p;
	t_coord	pi;

	if (s == 5)
		env->c = COLOR_ORANGE;
	pi = new_coord(r.x + s, r.y);
	p = new_coord(r.x + s, r.y);
	pf = new_coord(r.x, r.y);
	cercle(*env, pf, pi, p, 0);
	pf = new_coord(r.x, r.y + s);
	cercle(*env, pf, pi, p, -1);
	pf = new_coord(r.x, r.y - s);
	cercle(*env, pf, pi, p, 1);
}


void		draw_lem(t_env *env, t_room **room)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		if (room[i] && room[i]->dist < 10000)
			env->c = color(room[i]->dist);
		if (room[i] && room[i]->dist < 10000)
			draw_s(env, *room[i], 20);
		if (room[i] && room[i]->lem)
			draw_s(env, *room[i], 5);
		i++;
	}
}

int			fake_expose(t_env *envc)
{
	project(envc, envc->room);
	draw_lem(envc, envc->room);
	return (0);
}
