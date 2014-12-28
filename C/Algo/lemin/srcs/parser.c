/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/07 22:59:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				is_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	return (*str ? 0 : 1);
}

static t_lex	*get(t_lem **lem, t_lex *l)
{
	int			i;

	if (is_num(l->str) && (i = ft_atoi(l->str)))
	{
		*lem = (t_lem *)malloc(sizeof(t_lem));
		(*lem)->nbr = i;
		(*lem)->start = NULL;
		(*lem)->end = NULL;
		ft_bzero((*lem)->tab, 1000);
		return (l->next);
	}
	return (NULL);
}

static void		del_lex(t_lex **lex)
{
	t_lex		*t;

	if (*lex)
		(*lex)->prev->next = NULL;
	while (*lex)
	{
		t = (*lex)->next;
		ft_memdel((void **)&((*lex)->str));
		ft_memdel((void **)lex);
		*lex = t;
	}
}

void			del_lem(t_lem **lem)
{
	t_room		**room;
	int			i;

	i = 0;
	if (*lem)
	{
		room = (*lem)->tab;
		while (i < 1000)
		{
			if (room[i])
			{
				ft_memdel((void **)&(room[i]->lst));
				ft_memdel((void **)&(room[i]));
			}
			i++;
		}
		ft_memdel((void **)lem);
	}
}

t_lem			*parse(void)
{
	t_lem		*lem;
	t_lex		*lex;
	t_lex		*l;

	lem = NULL;
	lex = get_lst();
	l = get(&lem, lex);
	while (l && l != lex && lem)
	{
		if (!ft_strcmp(l->str, "##start"))
			l = get_door(lem, l->next, 1);
		else if (!ft_strcmp(l->str, "##end"))
			l = get_door(lem, l->next, 2);
		else if (ft_strchr(l->str, ' '))
			l = get_door(lem, l, 0);
		else if (ft_strchr(l->str, '-'))
			l = add_link(lem, l);
		else
			break ;
	}
	del_lex(&lex);
	return (lem);
}
