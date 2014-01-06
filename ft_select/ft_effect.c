/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:51:19 by msarr             #+#    #+#             */
/*   Updated: 2014/01/03 14:51:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_effect(t_list *list)
{
	char	buffer[3];
	t_list	*tmp;

	tmp = list;
	list = ft_setlist(list);
	while (1)
	{
		ft_putstr(tgoto(tgetstr("sc", NULL), tmp->col, tmp->row));
		ft_effect2(list);
		buffer[1] = 0;
		ft_putstr(tgetstr("me", NULL));
		read(0, buffer, 3);
		if (buffer[0] == 27)
		{
			if (buffer[1] == 91 && buffer[2] == 'B')
				tmp = tmp->next;
			if (buffer[1] == 91 && buffer[2] == 'A')
				tmp = tmp->prev;
			ft_putstr(tgoto(tgetstr("cm", NULL), tmp->col, tmp->row));
		}
		else if (buffer[0] == ' ')
		{
			if (tmp->select == 'y')
				tmp->select = 'n';
			else
				tmp->select = 'y';
		}
		else if (buffer[0] == 'q')
			return (0);
	}
}
