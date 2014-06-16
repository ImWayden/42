/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/11 19:02:10 by mozzie           ###   ########.fr       */
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
	t_lexlist		*tmp1;

	tmp = ft_listnew(str);
	if (!list)
		list = tmp;
	else
	{
		tmp1 = list;
		while (tmp1->next)
			tmp1 = tmp1->next;
		tmp->prev = tmp1;
		tmp1->next = tmp;
	}
	return (list);
}
