/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellistelmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 15:37:06 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 23:02:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_dellistelmt(t_select **list)
{
	t_select	*tmp;

	if ((tmp = *list))
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		ft_memdel((void **)&tmp->str);
		ft_memdel((void **)&tmp);
	}
}
