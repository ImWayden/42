/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/07 02:10:14 by mozzie           ###   ########.fr       */
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

int				is(t_lemlist *list, t_lem *lem)
{
	while (list)
	{
		if (!ft_strcmp(list->str, lem->end))
			return (1);
		list = list->next;
	}
	return (0);
}

void				recuparsetab(char *str, t_lem *pars, int *i)
{
	if (*i == 1)
		pars->start = (ft_strsplit(str, ' ')[0]);
	if (*i == 2)
		pars->end = (ft_strsplit(str, ' '))[0];
	if (*i == 1 || *i == 2)
		*i = 3;
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
			recuparsetab(str, pars, &i);
		free(str);
	}
	return (pars);
}

int main()
{
	t_lem		*lem;
	t_lemroom	**tabroom;
	t_lemroom	*room;
	int			i;
	

	lem = parse();
	ft_putendl("");	
	ft_putendl(lem->start);
	ft_putendl(lem->end);
	room = newroom(lem->start);
	ft_putendl(NULL);
	tabroom = recupfirstroom(room, lem);
	i = 0;
	while (tabroom && tabroom[i])
	{
		ft_putstr((tabroom[i])->name);
		ft_putstr(" ");
		i++;
	}
	ft_putendl("");
	while (tabroom && ft_strcmp((tabroom[0])->name, lem->end) && (tabroom = recupnextroom(tabroom, lem)))
	{
		i = 0;
		while (tabroom && tabroom[i])
		{
			ft_putendl((tabroom[i])->name);
			i++;
		}
	}
	ft_putendl("");
	ft_putendl(room->name);
	ft_putendl(((room->tab)[0])->name);
	//ft_putendl(((((room->tab)[0])->tab)[0])->name);
	return 0;
}