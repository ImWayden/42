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

#include "ft_printf.h"

t_list		*ft_add_list(t_list *list, char *str, int i)
{
	t_list	*tmp;
	t_list 	*tmp1;
	int		j;

	j = 0;
	tmp = (t_list *)malloc(sizeof(t_list));
	(*tmp).name = str[i];
	(*tmp).i = i;
	while (str[--i] != '%')
	{
		tmp->option[j] = str[i];
		j++;
	}
	tmp->next = NULL;
	if (list == NULL)
		list = tmp;
	else
	{
		tmp1 = list;
		while (tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
	}
	return (list);
}
