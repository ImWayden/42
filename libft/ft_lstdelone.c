/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 13:07:07 by msarr             #+#    #+#             */
/*   Updated: 2014/03/28 13:07:09 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (*alst)
	{
		del(&(*alst)->content, (*alst)->content_size);
		(*alst)->next = NULL;
		ft_memdel((void **)alst);
	} 
}
