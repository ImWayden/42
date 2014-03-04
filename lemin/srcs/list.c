/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 15:40:15 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemlist		*ft_lemlistnew(char *str)
{
	t_lemlist	*tmp;

	tmp = (t_lemlist *)ft_memalloc(1);
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