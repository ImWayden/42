/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:18:02 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:53:29 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

extern int	g_assign;

t_objet	*call_get_elem(t_objet *elem, char **tab, int *i, int f)
{
	g_assign = 10 * f;
	elem = get_elem(elem, tab, i);
	g_assign = 0;
	return (elem);
}

t_objet	*other_caracs(t_objet *elem, char **tab, int *i)
{
	if (ft_strcmp(tab[*i], "<MIDDLE>") == 0)
		elem = call_get_elem(elem, tab, i, 6);
	else if (ft_strcmp(tab[*i], "<PERTURB>") == 0)
		elem = call_get_elem(elem, tab, i, 7);
	return (elem);
}

t_objet *get_elem_obj(t_objet *elem, char **tab, int *i, int flag)
{
	if (flag == 1)
		(*i)++;
	while (tab[*i] != NULL && ft_strcmp(tab[*i], "<SPOT>") != 0
		&& ft_strcmp(tab[*i], "<SPHERE>") != 0
		&& ft_strcmp(tab[*i], "<PLAN>") != 0
		&& ft_strcmp(tab[*i], "<CYLINDRE>") != 0
		&& ft_strcmp(tab[*i], "<CONE>") != 0
		&& ft_strcmp(tab[*i], "<PARABOLOIDE>") != 0
		&& ft_strcmp(tab[*i], "<HYPERBOLOIDE>") != 0)
	{
		if (ft_strcmp(tab[*i], "<POS>") == 0)
			elem = call_get_elem(elem, tab, i, 1);
		else if (ft_strcmp(tab[*i], "<COL>") == 0)
			elem = call_get_elem(elem, tab, i, 2);
		else if (ft_strcmp(tab[*i], "<ROT>") == 0)
			elem = call_get_elem(elem, tab, i, 3);
		else if (ft_strcmp(tab[*i], "<SIZE>") == 0)
			elem = call_get_elem(elem, tab, i, 4);
		else if (ft_strcmp(tab[*i], "<BRILL>") == 0)
			elem = call_get_elem(elem, tab, i, 5);
		else
			elem = other_caracs(elem, tab, i);
	}
	return (elem);
}
