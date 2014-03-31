/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 02:10:52 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 14:05:08 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_lst	*init_list(t_lst *lst, t_lst *tmp)
{
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->prev = tmp;
	lst->j = lst->prev->j;
	lst->k = lst->prev->k;
	return (lst);
}

static t_lst	*start_list(t_lst *lst)
{
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->prev = NULL;
	lst->j = 0;
	lst->k = 0;
	return (lst);
}

t_lst			*ft_lstsplit(char const *s, char c)
{
	t_lst		*lst;
	t_lst		*tmp;

	lst = NULL;
	lst = start_list(lst);
	while (s[lst->k] != '\0' && lst && lst->k++)
	{
		if (s[lst->k] != c && s[lst->k] != '\0' && lst)
		{
			lst->j = lst->k;
			while (s[lst->j] != c && s[lst->j] != '\0')
				lst->j++;
			lst->str = ft_strsub(s, lst->k, (lst->j - lst->k));
			lst->k = lst->j - 1;
			tmp = lst;
			lst->next = init_list(lst, tmp);
			lst = lst->next;
		}
	}
	lst = lst->prev;
	lst->next = NULL;
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
