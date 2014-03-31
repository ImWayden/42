/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:57:57 by msarr             #+#    #+#             */
/*   Updated: 2014/03/03 13:58:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_getline		*ft_listnew(int i, char *str)
{
	t_getline	*tmp;

	tmp = (t_getline *)malloc(sizeof(t_getline));
	if (tmp)
	{
		tmp->fd = i;
		tmp->str = str;
		tmp->next = NULL;
	}
	return (tmp);
}

t_getline		*ft_addlist(t_getline *list, char *str, int i)
{
	t_getline	*tmp;

	tmp = ft_listnew(i, str);
	if (!list)
		tmp->next = list;
	return (tmp);
}
