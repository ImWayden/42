/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 18:00:29 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 18:00:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "bsq.h"



t_list			*bsq(t_list *list, int i, int j, int c, char **tab)
{
	t_list		*tmp;

	if (i == ft_atoi(tab[0]))
		return (0);
	if (ft_atoi(tab[0]) - i < c || ft_strlen(tab[1]) - j < c)
		return (0);
	else
	{
		tmp = list;
		while (tmp)
		{
			if (tmp->i >= i && tmp->i < i + c && tmp->j >= j && tmp->j < j + c)
			{
				if (j == ft_strlen(tab[1]) - 1)
					return (bsq(list, ++i, 0, c, tab));
				else
					return (bsq(list, i, ++j, c, tab));
			}
			tmp = tmp->next;
		}
		return (addlist(NULL, i, j));
	}
}
