/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 02:11:40 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemlist		*ft_listnew(int i, char *str)
{
	t_lemlist	*tmp;

	tmp = (t_lemlist *)malloc(sizeof(t_lemlist));
	if (tmp)
	{
		tmp->str = str;
		tmp->next = NULL;
	}
	return (tmp);
}

t_lemlist		*ft_addlist(t_lemlist *list, char *str)
{
	t_getline	*tmp;

	tmp = ft_listnew(i, str);
	if (!list)
		tmp->next = list;
	return (tmp);
}