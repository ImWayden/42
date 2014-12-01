/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:02:30 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/20 19:27:43 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	if (alst && *alst && (*alst)->next && del)
	{
		ft_lstdel(&((*alst)->next), del);
	}
	else if (alst && *alst && del)
	{
		del((void *)(*alst)->content, *(*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
