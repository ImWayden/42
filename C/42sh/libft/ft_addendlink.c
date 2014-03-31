/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addendlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:49:39 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:27:56 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list		*ft_addendlink(t_list *list, char *str)
{
	t_list	*new_elem;
	t_list	*tmp;

	new_elem = (t_list *)malloc(sizeof(t_list));
	tmp = (t_list *)malloc(sizeof(t_list));
	new_elem->str = str;
	if (list == NULL)
		return (new_elem);
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	return (list);
}