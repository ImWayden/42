/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 22:00:35 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 22:00:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ft_p(t_lex **list1, t_lex **list2, char c)
{
	t_lex	*tmp;

	if (*list1)
	{
		tmp = *list1;
		if (*list1 == (*list1)->next)
			*list1 = NULL;
		else
		{
			*list1 = (*list1)->next;
			(*list1)->prev = tmp->prev;
			tmp->prev->next = *list1;
		}
		if (!*list2)
		{
			*list2 = tmp;
			(*list2)->prev = tmp;
			(*list2)->next = tmp;
		}
		else
		{
			tmp->prev = (*list2)->prev;
			(*list2)->prev->next = tmp;
			tmp->next = *list2;
			(*list2)->prev = tmp;
			*list2 = (*list2)->prev;
		}
		write(1, "p", 1);
		write(1, &c, 1);
	}
}
