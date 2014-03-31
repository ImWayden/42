/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 02:24:51 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 14:28:56 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (*alst)
		{
			(*del)(tmp->content, tmp->content_size);
			*alst = (*alst)->next;
			free(tmp);
			tmp = NULL;
			tmp = *alst;
		}
	}
}
