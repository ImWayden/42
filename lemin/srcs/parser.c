/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/17 14:58:41 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void				recuproom(char *str, t_lem *pars, int *i)
{
	char			**tab;

	tab = ft_strsplit(str, ' ');
	if (*i == 1 || *i == 2)
	{
		if (*i == 1)
			pars->start = ft_strdup(tab[0]);
		else
			pars->end = ft_strdup(tab[0]);
		*i = 3;
	}
	pars->tab[hash(tab[0])] = allocroom(tab[0], pars);
	deltab(&tab);
}

void				recuptab(char *str, t_lem *pars)
{
	char			**tab;

	tab = ft_strsplit(str, '-');
	addroom(pars->tab[hash(tab[0])], tab[1], pars);
	addroom(pars->tab[hash(tab[1])], tab[0], pars);
	deltab(&tab);
}

t_lem				*parse()
{
	t_lem			*pars;
	int				i;
	char			*str = NULL;

	i = 0;
	pars = newlem();
	while (getnextline(0, &str) && ft_strlen(str))
	{
		ft_putendl(str);
		if (!i && *str != '#' && *str != 'L')
		{
			pars->j = ft_atoi(str);
			i = 3;
		}
		else if (!ft_strcmp(str, "##start") && i)
			i = 1;
		else if (!ft_strcmp(str, "##end") && i)
			i = 2;
		else if (*str == '#' || *str == 'L');
		else if (ft_is(str, ' ') && i)
			recuproom(str, pars, &i);
		else if (ft_is(str, '-') && i)
			recuptab(str, pars);
		ft_memdel((void **)&str);
	}
	return (pars);
}
