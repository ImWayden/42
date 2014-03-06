/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/06 09:39:09 by mozzie           ###   ########.fr       */
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

t_lemroom		**recupfirstroom(t_lemroom *room, t_lem *lem)
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
	lem->tab[hashcode(room->name)] = NULL;
	(room->tab)[i] = NULL;
	return (room->tab);
}

t_lemroom		**merge(t_lemroom **tabroom, t_lemroom **tabroom1)
{
	int			i;
	int			j;
	int			k;
	t_lemroom	**tabroom2;

	if(!tabroom1)
		return (tabroom);
	if(!tabroom)
		return (tabroom1);
	i = 0;
	j = 0;
	while (tabroom[i])
		i++;
	while (tabroom1[j])
		j++;
	tabroom2 = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + j + 1));
	tabroom2[i + j] = NULL;
	k = i;
	i--;
	j--;
	while (tabroom[i] || tabroom1[i + j])
	{
		if (tabroom[i])
			tabroom2[i] = tabroom[i];
		if (tabroom1[j])
			tabroom2[k + j] = tabroom1[j];
		i--;
	}
	return (tabroom2);
}

t_lemroom		**recupnextroom(t_lemroom **tabroom, t_lem *lem)
{
	t_lemroom	**tabroom1 = NULL;
	int			i;

	i = 0;
	while (tabroom && tabroom[i])
	{
		tabroom1 = merge(tabroom1, recupfirstroom(tabroom[i], lem));
		i++;
	}
	i = 0;
	while (tabroom[i])
	{
		if (ft_strcmp((tabroom[i])->name, lem->end))
			lem->tab[hashcode((tabroom[i])->name)] = NULL;
		i++;
	}
	return (tabroom1);
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

int main()
{
	t_lem		*lem;
	t_lemroom	**tabroom;
	t_lemroom	*room;
	int			i;
	

	lem = parse();	
	ft_putnbr(lem->j);
	ft_putendl((lem->tab[hashcode("1")])->str);
	ft_putendl("");
	room = newroom(lem->start);
	tabroom = recupfirstroom(room, lem);
	i = 0;
	while (tabroom[i])
	{
		ft_putendl((tabroom[i])->name);
		i++;
	}
	ft_putendl("");
	while ((tabroom = recupnextroom(tabroom, lem)))
	{
		i = 0;
		while (tabroom[i])
		{
			ft_putendl((tabroom[i])->name);
			i++;
		}
	}
	ft_putendl("");
	ft_putendl(room->name);
	ft_putendl(((room->tab)[0])->name);
	ft_putendl(((((room->tab)[0])->tab)[0])->name);
		return 0;
}