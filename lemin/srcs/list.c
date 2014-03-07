/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/06 23:41:23 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemlist		*ft_lemlistnew(char *str)
{
	t_lemlist	*tmp;

	if (!str)
		return (NULL);
	tmp = (t_lemlist *)malloc(sizeof(t_lemlist));
	if (tmp)
	{
		tmp->str = str;
		tmp->next = NULL;
	}
	return (tmp);
}

t_lemlist		*ft_addlemlist(t_lemlist *list, char *str)
{
	t_lemlist	*tmp;

	tmp = ft_lemlistnew(str);
	if (list)
		tmp->next = list;
	return (tmp);
}

int				ft_lemlistlen(t_lemlist *list)
{
	int			i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}