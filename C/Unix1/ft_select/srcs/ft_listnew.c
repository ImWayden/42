/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 15:07:37 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 23:01:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select			*ft_listnew(char *str, int pos)
{
	t_select		*list;

	if ((list = (t_select *)malloc(sizeof(t_select))))
	{
		list->str = ft_strdup(str);
		list->curseur = 'n';
		list->select = 'n';
		list->row = 0;
		list->col = 0;
		list->pos = pos;
		list->next = list;
		list->prev = list;
	}
	return (list);
}
