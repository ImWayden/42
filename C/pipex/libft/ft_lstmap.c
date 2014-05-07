/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 13:07:57 by msarr             #+#    #+#             */
/*   Updated: 2014/03/28 13:08:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if (lst && lst->next)
	{
		list = ft_lstmap(lst->next, f);
		ft_lstadd(&list, f(lst));
		return (list);
	}
	else if (lst)
		return (f(lst));
	else
		return (lst);
}
