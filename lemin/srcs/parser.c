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
	if (*i == 1)
		pars->start = (ft_strsplit(str, ' ')[0]);
	if (*i == 2)
		pars->end = (ft_strsplit(str, ' '))[0];
	if (*i == 1 || *i == 2)
		*i = 3;
	if (!ft_is(str, ' '))
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
		pars->tab[hashcode((ft_strsplit(str, ' '))[0])]
		= ft_lemlistnew((ft_strsplit(str, ' '))[0]);
		pars->list = ft_addlemlist(pars->list, (ft_strsplit(str, ' '))[0]);
	}	
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
			if (!ft_is(str, ' ') && !(pars->tab[hashcode((ft_strsplit(str, '-'))[0])]))
				return (NULL);
			recuparsetab(str, pars, &i);
		}
		free(str);
	}
	return (pars);
}
