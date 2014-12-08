/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:13:58 by msarr             #+#    #+#             */
/*   Updated: 2014/12/08 05:08:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


t_link		*new_link(t_room *room)
{
	t_link	*link;

	link = (t_link *)malloc(sizeof(t_link));
	if (link)
	{
		link->room = room;
		link->next = NULL;
	}
	return (link);
}

t_link		*link_lst(t_link *l, t_room *room)
{
	t_link	*link;

	link = new_link(room);
	link->next = l;
	return (link);
}

t_lex		*add_link(t_lem *lem, t_lex *l)
{
	char	**tab;
	t_room	*room;
	t_link	*link;

	if ((tab = ft_strsplit(l->str, '-')))
	{
		if (!*tab || !tab[1])
			return (NULL);
		room = lem->tab[hash(tab[0])];
		link = new_link(lem->tab[hash(tab[1])]);
		link->next = room->lst;
		room->lst = link;
		room = lem->tab[hash(tab[1])];
		link = new_link(lem->tab[hash(tab[0])]);
		link->next = room->lst;
		room->lst = link;
		return (l->next);
	}
	return (NULL);
}

t_link		*sort_link(t_link *l)
{
	t_link	*f;
	t_link	*n;
	t_room	*r;

	f = l;
	while (f)
	{
		n = f->next;
		while (n)
		{
			if (n->room->dist < f->room->dist)
			{
				r = n->room;
				n->room = f->room;
				f->room = r;
			}
			n = n->next;
		}
		f = f->next;
	}
	return (l);
}

t_trans		*new_trans(char	*src, char *dst)
{
	t_trans	*trans;

	trans = (t_trans *)malloc(sizeof(t_trans));
	if (trans)
	{
		trans->src = ft_strdup(src);
		trans->dst = ft_strdup(dst);
		trans->next = NULL;
	}
	return (trans);
}

t_trans		*add_trans(t_trans *trans, t_room *src, t_room *dst)
{
	t_trans	*new;

	new = new_trans(src->name, dst->name);
	new->next = trans;
	return (new);
}

void		put_trans(t_trans *trans)
{
	while (trans)
	{
		ft_putstr(trans->src);
		ft_putstr("->");
		ft_putendl(trans->dst);
		trans = trans->next;
	}
}