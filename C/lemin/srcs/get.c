/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 01:21:09 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				get_room(char *str, t_lem *pars)
{
	char			**tab;

	tab = ft_strsplit(str, ' ');
	pars->tab[hash(tab[0])] = allocroom(tab[0]);
	deltab(&tab);
}

void				get_tab(char *str, t_lem *pars)
{
	char			**tab;

	tab = ft_strsplit(str, '-');
	addroom(pars->tab[hash(tab[0])], tab[1]);
	addroom(pars->tab[hash(tab[1])], tab[0]);
	deltab(&tab);
}
