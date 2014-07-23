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

t_bsq_list			*ft_bsq(int i, int j, int c, t_bsq *bsq)
{
	t_bsq_list		*tmp;

	if (i == bsq->l_max)
		return (0);
	if (bsq->l_max - i < c || bsq->c_max - j < c)
		return (0);
	else
	{
		tmp = bsq->list;
		while (tmp && tmp->next)
		{
			if (tmp->i >= i && tmp->i < i + c && tmp->j >= j && tmp->j < j + c)
			{
				if (j == bsq->c_max - 1)
					return (ft_bsq(++i, 0, c, bsq));
				else
					return (ft_bsq(i, ++j, c, bsq));
			}
			tmp = tmp->next;
		}
		return (addlist(NULL, i, j));
	}
}
