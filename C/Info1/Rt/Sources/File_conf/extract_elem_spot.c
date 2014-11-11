/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_elem_spot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:12:31 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:40:44 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

extern int	g_assign;

void	extract_spot(t_spot **elem, char **tab, int *i)
{
	int		j;
	int		k;
	int		count;
	char	*new;

	j = 0;
	k = 0;
	count = get_count_of_extract(tab, i);
	new = malloc(sizeof(*new) * (ft_strlen(tab[*i]) - count + 1));
	while (tab[*i][j] != '\0')
	{
		if (tab[*i][j] != '<' && tab[*i][j] != '>'
			&& tab[*i][j] != 'X' && tab[*i][j] != 'R'
			&& tab[*i][j] != 'Y' && tab[*i][j] != 'G'
			&& tab[*i][j] != 'Z' && tab[*i][j] != 'B')
		{
			new[k] = tab[*i][j];
			k++;
		}
		j++;
	}
	new[k] = '\0';
	assign_value_spot(elem, new);
	free(new);
}

t_spot	*call_extract_spot(t_spot *elem, char **tab, int *i, int f)
{
	g_assign = g_assign + f;
	extract_spot(&elem, tab, i);
	g_assign = g_assign - f;
	return (elem);
}

t_spot	*extract_elem_spot(t_spot *elem, char **tab, int *i)
{
	while (tab[++(*i)] != NULL && ft_strcmp(tab[*i], "<OBJ>") != 0 &&
		ft_strcmp(tab[*i], "<POS>") != 0 &&
		ft_strcmp(tab[*i], "<COL>") != 0 &&
		ft_strcmp(tab[*i], "<SPOT>") != 0)
	{
		if (ft_strncmp(tab[*i], "<X>", 3) == 0 ||
			ft_strncmp(tab[*i], "<R>", 3) == 0)
			elem = call_extract_spot(elem, tab, i, 1);
		else if (ft_strncmp(tab[*i], "<Y>", 3) == 0 ||
			ft_strncmp(tab[*i], "<G>", 3) == 0)
			elem = call_extract_spot(elem, tab, i, 2);
		else if (ft_strncmp(tab[*i], "<Z>", 3) == 0 ||
			ft_strncmp(tab[*i], "<B>", 3) == 0)
			elem = call_extract_spot(elem, tab, i, 3);
	}
	return (elem);
}
