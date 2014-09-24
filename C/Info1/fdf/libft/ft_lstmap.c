/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:05:07 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/20 19:27:53 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list			*ft_lstmap(t_list *list, t_list *(*f) (t_list *elem))
{
	t_list		*tmp;

	if (list && list->next && f)
	{
		tmp = ft_lstmap(list->next, f);
		ft_lstadd(&tmp, f(list));
		return (tmp);
	}
	else if (list && f)
	{
		return (f(list));
	}
	else
	{
		return (NULL);
	}
}
