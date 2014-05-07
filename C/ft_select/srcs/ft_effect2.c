/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:13:10 by msarr             #+#    #+#             */
/*   Updated: 2014/01/04 15:13:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static	void		choice2(t_selectlist *list)
{
	ft_putstr(tgoto(tgetstr("cm", NULL), list->col, list->row));
	if (list->select == 'y')
		ft_putstr(tgetstr("mr", NULL));
	if (list->curseur == 'y')
		ft_putstr(tgetstr("us", NULL));
	ft_putendl(list->str);
	ft_putstr(tgetstr("me", NULL));
}

int					ft_effect2(t_selectlist *list)
{
	t_selectlist	*tmp;

	ft_putstr(tgetstr("cl", NULL));
	tmp = list;
	choice2(tmp);
	tmp = tmp->next;
	while (tmp != list)
	{
		choice2(tmp);
		tmp = tmp->next;
	}
	return (0);
}
