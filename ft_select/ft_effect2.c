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

static	void	choice(t_list *list)
{
	ft_putstr(tgoto(tgetstr("cm", NULL), list->col, list->row));
	if (list->select == 'y')
	{
		ft_putstr(tgetstr("mr", NULL));
		ft_putstr(list->str);
		ft_putstr(tgetstr("me", NULL));
	}
	else
		ft_putstr(list->str);
}

int		ft_effect2(t_list *list)
{
	t_list	*tmp;

	ft_putstr(tgetstr("cl", NULL));
	tmp = list;
	/*if (tmp->select == 'y')
	{
		ft_putstr(tgetstr("mr", NULL));
		ft_putstr(tmp->str);
		ft_putstr(tgetstr("me", NULL));
	}
	else
		ft_putstr(tmp->str);*/
	choice(tmp);
	tmp = tmp->next;
	while(tmp != list)
	{
		/*ft_putstr(tgoto(tgetstr("cm", NULL), tmp->col, tmp->row));
		if (tmp->select == 'y')
			ft_putstr(tgetstr("mr", NULL));
		ft_putstr(tmp->str);
		if (tmp->select == 'y')
			ft_putstr(tgetstr("me", NULL));*/ choice(tmp);
		tmp = tmp->next;
	}
	ft_putstr(tgetstr("rc", NULL));
	return (0);
}
