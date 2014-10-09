/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:59 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:57:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_putlist(t_selectlist *list)
{
	t_selectlist	*tmp;

	tmp = list;
	if (tmp)
	{
		ft_putstr(tmp->str);
		write(1, "\n", 1);
		tmp = tmp->next;
		while (tmp != list)
		{
			ft_putstr(tmp->str);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
}

void				ft_sendlist(t_selectlist *list)
{
	t_selectlist	*tmp;

	ft_putstr(tgetstr("cl", NULL));
	ft_putstr(tgetstr("me", NULL));
	tmp = list;
	if (tmp && tmp->select == 'y')
	{
		write(1, tmp->str, ft_strlen(tmp->str));
		write(1, " ", 1);
		tmp = tmp->next;
		while (tmp && tmp != list)
		{
			if (tmp->select == 'y')
				write(1, tmp->str, ft_strlen(tmp->str));
			if (tmp->select == 'y')
				write(1, " ", 1);
			tmp = tmp->next;
		}
		ft_putstr(tgetstr("le", NULL));
	}
}