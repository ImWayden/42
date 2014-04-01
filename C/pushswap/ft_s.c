/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 19:20:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 19:20:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ft_s(t_list *list)
{
	int		i;

	if (list && list->next)
	{
		i = list->i;
		list->i = list->next->i;
		list->next->i = i;
		write(1, "s", 1);
	}
}