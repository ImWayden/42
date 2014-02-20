/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 14:00:48 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 15:10:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

t_list		*ft_asortlist(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp1;
	char	*str;
	char	*str1;
	
	tmp = list;
	while (tmp->next)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (strcmp(tmp->atime, tmp1->atime) > 0)
			{
				str = ft_strnew((size_t)ft_strlen(tmp->str));
				str1 = ft_strnew((size_t)ft_strlen(tmp->str));
				str = ft_strcpy(str,tmp->str);
				str1 = ft_strcpy(str,tmp->str);
				tmp->str = ft_strcpy(tmp->str, tmp1->str);
				tmp->atime = ft_strcpy(tmp->atime, tmp1->atime);
				tmp1->str = ft_strcpy(tmp1->str, str);
				tmp1->atime = ft_strcpy(tmp1->atime, str1);
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (list);
}
