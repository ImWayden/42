/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 13:07:45 by msarr             #+#    #+#             */
/*   Updated: 2014/03/28 13:07:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}
