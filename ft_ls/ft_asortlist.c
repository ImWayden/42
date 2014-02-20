/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asortlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 19:19:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 19:19:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lsft.h"

t_list		*ft_asortlist(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp1;
	
	tmp = list;
	while (tmp->next)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (ft_strcmp(tmp->atime, tmp1->atime) > 0)
				ft_listswap(tmp, tmp1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (list);
}
