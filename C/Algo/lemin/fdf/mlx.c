/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:20:56 by msarr             #+#    #+#             */
/*   Updated: 2014/12/10 19:30:09 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lemin.h"

int				color(int i)
{
	int			tab[10];

	tab[0] = COLOR_WHITE;
	tab[1] = COLOR_GREEN;
	tab[2] = COLOR_YELLOW;
	tab[3] = COLOR2_BLUE;
	tab[4] = COLOR_ORANGE;
	tab[5] = COLOR2_RED;
	tab[6] = COLOR2_GREEN;
	return (tab[i]);
}

t_coord			new_coord(float x, float y)
{
	t_coord		new;

	new.x = x;
	new.y = y;
	return (new);
}

t_coord			point(t_coord c, int x, int y, int i)
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

void	 		cercle(t_env env, t_coord c, t_coord s, t_coord e, int flag)
{
	t_coord 	p;
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
				pixel_put(&env, p.x, p.y, env.c);
			else if (p.y >= s.y && p.y >= e.y && flag == 1)
				pixel_put(&env, p.x, p.y, env.c);
			else if (p.y <= s.y && p.y <= e.y && flag == -1)
				pixel_put(&env, p.x, p.y, env.c);
			i++;
		}
		if (d >= 2*x)
		{
			d -= 2 * x + 1;
			x ++;
		}
		else if (d < 2 * (r-y))
		{
			d += 2 * y - 1;
			y --;
		}
		else
		{
			d += 2 * (y - x - 1);
			y --;
			x ++;
		}
	}
}

void		draw_s(t_env *env, t_room r, int s)
{
	t_coord	pf;
	t_coord	p;
	t_coord	pi;

	pi = new_coord(r.x + s, r.y);
	p = new_coord(r.x + s, r.y);
	pf = new_coord(r.x, r.y);
	cercle(*env, pf, pi, p, 0);
	pf = new_coord(r.x, r.y + s);
	cercle(*env, pf, pi, p, -1);
	pf = new_coord(r.x, r.y - s);
	cercle(*env, pf, pi, p, 1);
}

t_room		*nav(t_env *env, t_room **room, t_trans *t, int i)
{
	t_room	*s;
	t_room	*d;
	int		r;

	s = room[hash(t->src)];
	d = room[hash(t->dst)];
	r = sqrt(SQUARE(s->x - d->x) + SQUARE(s->y - d->y));
	r = r * i / 100;
	return (drawline(*env, *s, *d, r));
}

void		drawlink(t_env *env, t_link *l, int c)
{
	while (l)
	{
		env->c = c;
		draw_s(env, *(l->room), 5);
		l = l->next;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}

void		draw_start(t_env *env)
{
	int		i;
	int 	j;

	i = 0;
	j = env->pad;
	while (i <= j)
	{
		env->c = color(i % 7);
		draw_s(env, *env->lem->start, i);
		i += 5;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}

void		drawroom(t_env *env, t_room **room)
{
	t_link	*l;
	int		i;

	i = 0;
	while (i < 1000)
	{
		if (room[i] && room[i]->dist && room[i] != env->lem->start)
		{
			env->c = color(room[i]->dist % 7);
			draw_s(env, *room[i], env->pad / 2);
			l = room[i]->lst;
			while (l)
			{
				drawline(*env, *room[i], *l->room, 120000);
				l = l->next;
			}
		}
		i++;
	}
}

void		draw_end(t_env *env, t_room *room)
{
	int		i;

	i = 1;
	while (i <= room->lem && i <= env->pad / 2)
	{
		env->c = color(i % 7);
		draw_s(env, *room, i * 2);
		i += 5;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}

void		draw_lem(t_env *env, t_room **room, t_trans *t)
{
	int		j;
	double	k;
	t_trans	*s;
	t_link	*l;
	t_room	*r;

	j = 0;
	k = 1;	
	drawroom(env, room);
	draw_start(env);
	while (j <= 100)
	{
		s = t;
		l = NULL;
		while (s)
		{
			if ((r = nav(env, room, s, j)))
				l = link_lst(l, r);
			s = s->next;
		}
		drawlink(env, l, COLOR_BLUE);
		drawlink(env, l, COLOR_BLACK);
		drawroom(env, room);
		draw_start(env);
		k += 0.04;
		j = (int)k;
	}
	draw_end(env, env->lem->end);
}

int			fake_expose(t_env *env)
{
	int				i;
	t_lem			*lem;
	t_trans			*t;

	lem = env->lem;
	while (lem->end->lem < lem->nbr)
	{
		i = 0;
		t = NULL;
		while (i < 1000)
		{
			if (lem->tab[i])
			{
				lem->tab[i]->s = 0;
				lem->tab[i]->r = 0;
			}
			i++;
		}
		t = send(lem->start, lem, t);
		draw_lem(env, env->room, t);
		ft_putendl("");
	}
	return (EXIT_SUCCESS);
}
