/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:41:15 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:41:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_selectlistlen(t_selectlist *list)
{
	t_selectlist		*tmp;
	int			i;

	i = 0;
	tmp = list;
	if (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp != list)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_selectlist		*ft_addlist(t_selectlist *list, char *str)
{
	t_selectlist	*tmp;

	tmp = (t_selectlist *)malloc(sizeof(t_selectlist));
	tmp->str = ft_strdup(str);
	tmp->curseur = 'n';
	tmp->select = 'n';
	if (list == NULL)
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

t_selectlist		*ft_dellistelmt(t_selectlist *list, char *str)
{
	t_selectlist	*tmp;

	tmp = list;
	if (list != NULL)
	{
		if (ft_selectlistlen(list) == 1)
			list = NULL;
		else
		{
			while (ft_strcmp(tmp->str, str))
				tmp = tmp->next;
			tmp->next->curseur = 'y';
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			free(tmp);
		}
	}
	return (list);
}
