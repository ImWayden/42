/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 13:07:29 by msarr             #+#    #+#             */
/*   Updated: 2014/03/28 13:07:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && (*alst)->next)
		ft_lstdel(&((*alst)->next), del);
	else if (alst && *alst)
	{
		del((void *)(*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
