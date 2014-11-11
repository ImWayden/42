/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:06:55 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:20:26 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

extern int	g_assign;

int		get_count_of_extract(char **tab, int *i)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (tab[*i][j] != '\0')
	{
		if (tab[*i][j] == '<' || tab[*i][j] == '>'
			|| tab[*i][j] == 'X' || tab[*i][j] == 'R'
			|| tab[*i][j] == 'Y' || tab[*i][j] == 'G'
			|| tab[*i][j] == 'Z' || tab[*i][j] == 'B')
			count++;
		j++;
	}
	return (count);
}

void	extract_elem(t_objet **elem, char **tab, int *i)
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
	assign_value(elem, new);
	free(new);
}

t_objet	*call_extract_elem(t_objet *elem, char **tab, int *i, int f)
{
	g_assign = g_assign + f;
	extract_elem(&elem, tab, i);
	g_assign = g_assign - f;
	return (elem);
}

t_objet	*get_elem(t_objet *elem, char **tab, int *i)
{
	int		type;

	type = 1;
	while (tab[++(*i)] != NULL && check_limit_while(tab, i) == 1)
	{
		if (ft_strncmp(tab[*i], "<X>", 3) == 0
			|| ft_strncmp(tab[*i], "<R>", 3) == 0)
			elem = call_extract_elem(elem, tab, i, type);
		else if (ft_strncmp(tab[*i], "<Y>", 3) == 0
			|| ft_strncmp(tab[*i], "<G>", 3) == 0)
			elem = call_extract_elem(elem, tab, i, type);
		else if (ft_strncmp(tab[*i], "<Z>", 3) == 0
			|| ft_strncmp(tab[*i], "<B>", 3) == 0)
			elem = call_extract_elem(elem, tab, i, type);
		else
			elem = call_extract_elem(elem, tab, i, type);
		type++;
	}
	return (elem);
}
