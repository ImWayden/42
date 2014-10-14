/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:13:10 by msarr             #+#    #+#             */
/*   Updated: 2014/10/14 00:16:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static	void		choice2(t_select *list)
{
	ft_putstr(tgoto(tgetstr("cm", NULL), list->col, list->row));
	if (list->select == 'y')
		ft_putstr(tgetstr("mr", NULL));
	if (list->curseur == 'y')
		ft_putstr(tgetstr("us", NULL));
	ft_putendl(list->str);
	ft_putstr(tgetstr("me", NULL));
}

int					ft_effect2(t_select *list)
{
	t_select		*tmp;

	ft_putstr(tgetstr("cl", NULL));
	tmp = list;
	while (tmp)
	{
		choice2(tmp);
		if ((tmp = tmp->next) == list)
			break ;
	}
	return (0);
}
