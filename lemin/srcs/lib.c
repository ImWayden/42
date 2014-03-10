/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:56:02 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 14:56:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lem				*newlem(void)
{
	t_lem			*pars;
	int				i;

	pars = (t_lem *)malloc(sizeof(t_lem));
	pars->start = NULL;
	pars->end = NULL;
	i = 0;
	while (((pars->tab)[i] = NULL))
		i++;
	return(pars);
}

t_lemlist					*is(t_lemlist *list, t_lem *lem)
{
	t_lemlist				*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->str, lem->end))
			return (tmp);
		tmp = tmp->next;
	}
	return (list);
}

void				sort(t_lemroom **tabroom)
{
	int				i;
	int				j;

	i = 0;
	while (tabroom && tabroom[i])
	{
		j = i + 1;
		while (tabroom[j])
		{
			if ((tabroom[i])->dist > (tabroom[j])->dist && (tabroom[j])->dist)
				ft_swap((void **)&(tabroom[i]), (void **)&(tabroom[j]));
			if (!(tabroom[i])->dist)
				ft_swap((void **)&(tabroom[i]), (void **)&(tabroom[j]));
			j++;
		}
		i++;
	}
}
