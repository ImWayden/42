/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:08:31 by msarr             #+#    #+#             */
/*   Updated: 2014/02/05 14:08:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

t_list		*ft_addlist(t_list *list, char *str)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->str = ft_strdup(str);
	tmp->next = NULL;
	tmp->prev = NULL;
	if (list)
	{
		tmp->next = list;
		list->prev = tmp;
	}
	return (tmp);
}

t_list		*ft_editlist(t_list *list, char *str)
{
	list->str = ft_strjoin(list->str, str);
	return (list);
}