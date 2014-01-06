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

static	t_list	*choice(t_list **tmp, char *buffer)
{
	if (buffer[0] == 27)
	{
		(*tmp)->curseur = 'n';
		if (buffer[1] == 91 && buffer[2] == 'B')
			(*tmp) = (*tmp)->next;
		if (buffer[1] == 91 && buffer[2] == 'A')
			(*tmp) = (*tmp)->prev;
		(*tmp)->curseur = 'y';
	}
	else if (buffer[0] == ' ')
	{
		if ((*tmp)->select == 'y')
			(*tmp)->select = 'n';
		else
			(*tmp)->select = 'y';
		(*tmp) = (*tmp)->next;
	}
	return (*tmp);
}

void    mywinch(int i)
{
	exit;
}

int		ft_effect(t_list *list)
{
	char	buffer[3];
	t_list	*tmp;

	tmp = list;
	while (1)
	{
		//signal(SIGWINCH, mywinch);
		list = ft_setlist(list);
		ft_effect2(list);
		ft_putstr(tgoto(tgetstr("cm", NULL), tmp->col, tmp->row));
		buffer[0] = 0;buffer[1] = 0;buffer[2] = 0;	
		read(0, buffer, 3);
		tmp = choice(&tmp, buffer);
		if (buffer[0] == 'q')
		{
			ft_putstr(tgetstr("cl", NULL));
			ft_putstr(tgetstr("me", NULL));
			return (0);
		}
	}
}

