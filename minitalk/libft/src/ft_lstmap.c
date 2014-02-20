/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 00:51:55 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 14:03:34 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	**start;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	start = &tmp;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		lst = lst->next;
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp = tmp->next;
		if (!tmp)
			return (NULL);
	}
	return ((t_list *)start);
}
