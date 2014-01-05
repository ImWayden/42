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
	tmp->curseur = 'y';
	while (1)
	{
		ft_effect2(list);
		buffer[2] = 0;
		read(0, buffer, 3);
		if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 'B')
		{
			tmp->curseur = 'n';
			tmp = tmp->next;
			tmp->curseur = 'y';
		}
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 'A')
		{
			tmp->curseur = 'n';
			tmp = tmp->prev;
			tmp->curseur = 'y';
		}
		else if (buffer[0] == ' ')
		{
			if (tmp->select == 'y')
				tmp->select = 'n';
			else
				tmp->select = 'y';
		}
		else if (buffer[0] == 27)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
}
