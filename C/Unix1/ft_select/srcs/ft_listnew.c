/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 15:07:37 by msarr             #+#    #+#             */
/*   Updated: 2014/05/02 15:07:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_selectlist			*ft_listnew(char *str)
{
	t_selectlist		*list;

	if ((list = (t_selectlist *)malloc(sizeof(t_selectlist))))
	{
		list->str = ft_strdup(str);
		list->curseur = 'n';
		list->select = 'n';
		list->row = 0;
		list->col = 0;
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}
