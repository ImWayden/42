/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/09 15:03:52 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

static t_lexlist	*ft_listnew(char *str)
{
	t_lexlist		*list;

	if ((list = (t_lexlist *)malloc(sizeof(t_lexlist))))
	{
		list->str = str;
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}

t_lexlist			*addlist(t_lexlist *list, char *str)
{
	t_lexlist		*tmp;

	tmp = ft_listnew(str);
	if (!list)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		list = tmp;
	}
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	return (list);
}
