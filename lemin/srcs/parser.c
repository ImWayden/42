/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 16:55:14 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			hashcode(char *str)
{
	int		code;
	int		len;
	int		i;

	len = ft_strlen(str);
	code = 7;
	i = 0;
	while (i < len)
	{
		code = str[i] + 31 * code;
		i++;
	}
	return (code % 1000);
}

t_lem				*parse()
{
	t_lem			*pars;
	int				i;
	char			*str = NULL;

	i = 0;
	pars = (t_lem *)malloc(sizeof(t_lem));
	while (getnextline(0, &str))
	{
		ft_putendl(str);
		if (!i)
		{
			pars->j = ft_atoi(str);
			i = 3;
		}
		else if (!ft_strcmp(str, "##start"))
			i = 1;
		else if (!ft_strcmp(str, "##end"))
			i = 2;
		else if (i && *str != '#')
		{
			if (i == 1)
				pars->start = (ft_strsplit(str, ' ')[0]);
			if (i == 2)
				pars->end = (ft_strsplit(str, ' '))[0];
			if (i == 1 || i == 2)
				i = 3;
			if (ft_is(str, '-'))
			{
				pars->tab[hashcode((ft_strsplit(str, '-'))[0])]
				= ft_addlemlist(pars->tab[hashcode((ft_strsplit(str, '-'))[0])]
				, (ft_strsplit(str, '-'))[1]);
				pars->tab[hashcode((ft_strsplit(str, '-'))[1])]
				= ft_addlemlist(pars->tab[hashcode((ft_strsplit(str, '-'))[1])]
				, (ft_strsplit(str, '-'))[0]);
			}
			else
			{
				pars->tab[hashcode((ft_strsplit(str, ' '))[0])] = ft_lemlistnew(NULL);
				pars->list = ft_addlemlist(pars->list, (ft_strsplit(str, ' '))[0]);
			}
			free(str);
		}
	}
	return (pars);
}

void		recupnextroom(t_lemroom *room, t_lem *lem)
{
	t_lemlist	*list;
	int			i;

	list = lem->tab[hashcode(room->name)];
	i = ft_lemlistlen(list);
	room->tab = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + 1));
	(room->tab)[i] = NULL;
	i = 0;
	while (list && room)
	{
		if (list->str && ft_strcmp(list->str, lem->start))
		{
			(room->tab)[i] = newroom(list->str);
			i++;
		} 
		list = list->next;
	}
	(room->tab)[i] = NULL;
}

t_lemroom		*newroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		if (str)
			room->name = ft_strdup(str);
		else
			room->name = NULL;
		room->tab  = NULL;
	}
	return (room);
}

t_lemroom		*recupallroom(t_lemroom *room, t_lem *lem)
{
}

void			dsaput(t_lemroom *room)
{
	int			i;
	t_lemroom	**tab;

	
	ft_putendl(room->name);
	tab = room->tab;
	i = 0;
	while (tab && tab[i])
	{
		ft_putstr(((tab)[i])->name);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	i = 0;
	while (tab && tab[i])
	{
		dsaput(tab[i]);
		i++;
	}
	ft_putstr("\n");
}

int main()
{
	t_lem		*lem;
	t_lemroom	*room;
	

	lem = parse();	
	ft_putnbr(lem->j);
	ft_putendl((lem->tab[hashcode("1")])->str);
	ft_putendl("");
	room = newroom(lem->start);
	room = recupallroom(room, lem);
	ft_putendl("");
	dsaput(room);
	return 0;
}