/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:59 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 22:18:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_sendlist(t_select *list)
{
	t_select		*tmp;
	int				i;

	i = 0;
	ft_putstr(tgetstr("cl", NULL));
	ft_putstr(tgetstr("me", NULL));
	tmp = list;
	while (tmp)
	{
		if (tmp->select == 'y')
		{
			if (i)
				write(1, " ", 1);
			ft_putstr(tmp->str);
			i = 1;
		}
		if ((tmp = tmp->next) == list)
			break ;
	}
}
