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

int		ft_effect2(t_list *list)
{
	char	*clearscreen;
	t_list	*tmp;

	ft_putstr(tgetstr("cl", NULL));
	tmp = list;
	if (tmp->curseur == 'y')
			ft_putstr(tgetstr("us", NULL));
	if (tmp->select == 'y')
			ft_putstr(tgetstr("md", NULL));	
	ft_putstr(tmp->str);
	write(1, "\n", 1);
	if (tmp->curseur == 'y'|| tmp->select == 'y')
		ft_putstr(tgetstr("me", NULL));
	tmp = tmp->next;
	while(tmp != list)
	{
		if (tmp->curseur == 'y')
			ft_putstr(tgetstr("us", NULL));
		if (tmp->select == 'y')
			ft_putstr(tgetstr("md", NULL));
		ft_putstr(tmp->str);
		write(1, "\n", 1);
		if (tmp->curseur == 'y' || tmp->select == 'y')
			ft_putstr(tgetstr("me", NULL));
		tmp = tmp->next;
	}
	tmp = list->prev;
	while (tmp->curseur != 'y' && tmp != list)
	{
		tmp = tmp->prev;
		ft_putstr(tgetstr("up", NULL));
	}
	ft_putstr(tgetstr("up", NULL));
	return (0);
}
