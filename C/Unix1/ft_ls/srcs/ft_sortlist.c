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

static void				ft_listswap(t_dirlist *tmp, t_dirlist *tmp1)
{
	time_t				atime;
	char				*str;

	str = tmp->str;
	atime = tmp->atime;
	tmp->atime = tmp1->atime;
	tmp->str = tmp1->str;
	tmp1->str = str;
	tmp1->atime = atime;
}

t_dirlist				*ft_sortlist(t_dirlist *list, int i, int j)
{
	t_dirlist			*tmp;
	t_dirlist			*tmp1;

	tmp = list;
	while (tmp && tmp->next)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (ft_strcmp(tmp->str, tmp1->str) > 0 && !j && !i)
				ft_listswap(tmp, tmp1);
			if (ft_strcmp(tmp->str, tmp1->str) < 0 && !j && i)
				ft_listswap(tmp, tmp1);
			if (tmp->atime < tmp1->atime && j && !i)
				ft_listswap(tmp, tmp1);
			if (tmp->atime > tmp1->atime && j && i)
				ft_listswap(tmp, tmp1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (list);
}
