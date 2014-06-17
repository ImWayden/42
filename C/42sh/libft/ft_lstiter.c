/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 13:39:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/28 13:39:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst && lst->next)
		f(lst->next);
	else if (lst)
		f(lst);
}