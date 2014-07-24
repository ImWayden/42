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

void			delbsq(t_bsq **bsq)
{
	t_bsq_list	*tmp;
	if (bsq && *bsq)
	{
		ft_memdel((void **)&((*bsq)->str));
		while ((*bsq)->list)
		{
			tmp = (*bsq)->list;
			(*bsq)->list = (*bsq)->list->next;
			tmp->next = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
}

void			ft_puttab(t_bsq *bsq, t_bsq_list *list, int c)
{
	int			i;
	int			j;
	t_bsq_list	*tmp;

	i = -1;
	tmp = bsq->list;
	while (++i < bsq->l_max)
	{
		j = 0;
		while (j < bsq->c_max)
		{
			if (i >= list->i && i < list->i + c
				&& j >= list->j && j < list->j + c)
				ft_putchar(bsq->str[2]);
			else if (tmp && (i == tmp->i && j == tmp->j))
			{
				ft_putchar(bsq->str[1]);
				tmp = tmp->next;
			}
			else
				ft_putchar(bsq->str[0]);
			j++;
		}
		ft_putchar ('\n');
	}
}

void			before_bsq(t_bsq **bsq)
{
	int			k;
	t_bsq_list	*rslt;

	if ((*bsq)->list)
		(*bsq)->list->prev->next = NULL;
	k = ((*bsq)->l_max > (*bsq)->c_max) ? (*bsq)->c_max : (*bsq)->l_max;
	while (k > 1 && !(rslt = ft_bsq(0, 0, k, *bsq)))
		k--;
	if (k != 1)
		ft_puttab(*bsq, rslt, k);
	delbsq(bsq);
}

t_bsq_list		*ft_bsq(int i, int j, int c, t_bsq *bsq)
{
	t_bsq_list	*tmp;

	if (i == bsq->l_max)
		return (0);
	if (bsq->l_max - i < c || bsq->c_max - j < c)
	{
		if (j == bsq->c_max - 1)
			return (ft_bsq(++i, 0, c, bsq));
		else
			return (ft_bsq(i, ++j, c, bsq));
	}
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
