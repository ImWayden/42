/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 17:26:48 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 17:56:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_ord_alphlong.h"

t_list		*ft_addlist(t_list *list, char *str)
{
	t_list		*tmp;
	t_list		*new;

	tmp = list;
	new->str = str;
	if (list)
	{
		while (tmp->next)
		{
			if (ft_strlen(str) > ft_strlen(tmp->str))
				tmp = tmp->next;
		}
		new->next = tmp->next;
		tmp->next = new;
	}
	else
	{
		new->next = NULL;
		list = new;
	}
	return (list);
}

int		main(int argc, char **argv)
{
	int i = 0;
	t_list	*list;

	list = NULL;
	if (argc > 1)
	{
		while (i < argc)
			list = ft_addlist(list, argv[i]);
		while (list)
		{
			printf("%s\n", list->str);
			list = list->next;
		}
	}
	return (0);
}

