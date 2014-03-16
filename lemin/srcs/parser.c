/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/12 16:01:03 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void				recuparsetab(char *str, t_lem *pars, int *i)
{
	char	**tab;

	if (*i == 1 || *i == 2)
	{
		tab = ft_strsplit(str, ' ');
		if (*i == 1)
			pars->start = ft_strdup(tab[0]);
		else
			pars->end = ft_strdup(tab[0]);
		*i = 3;
		deltab(&tab);
	}
	if (!ft_is(str, ' '))
	{
		tab = ft_strsplit(str, '-');
		addroom(pars->tab[hash(tab[0])], tab[1]);
		addroom(pars->tab[hash(tab[1])], tab[0]);
	}
	else
	{
		tab = ft_strsplit(str, ' ');
		pars->tab[hash(tab[0])] = allocroom(tab[0]);
	}
	deltab(&tab);
}

static	int		isgood(char *str, t_lem *pars)
{
	char			**tab;

	if (!ft_is(str, ' '))
	{
		tab = ft_strsplit(str, '-');
		if (!(pars->tab[hash(tab[0])]))
		{
			deltab(&tab);
			return (1);
		}
		deltab(&tab);
	}
	return (0);
}

t_lem				*parse()
{
	t_lem			*pars;
	int				i;
	char			*str = NULL;

	i = 0;
	pars = newlem();
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
			if (isgood(str, pars))
				return (pars);
			else
				recuparsetab(str, pars, &i);
		}
		ft_memdel((void **)&str);
	}
	return (pars);
}
