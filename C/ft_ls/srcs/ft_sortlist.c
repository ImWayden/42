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

static void				ft_listswap(t_dirlist **tmp, t_dirlist **tmp1)
{
	t_dirlist			*tmp2;

	tmp2 = *tmp;
	*tmp = *tmp1;
	*tmp1 = tmp2;
}


t_dirlist				*ft_sortlist(t_dirlist **list)
{
	t_dirlist			*tmp;
	t_dirlist			*tmp1;
	
	tmp = *list;
	while (tmp && tmp->next)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (ft_strcmp(tmp->atime, tmp1->atime) > 0)
				ft_listswap(&tmp, &tmp1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (*list);
}
