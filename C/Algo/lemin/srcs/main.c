/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 21:20:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "fdf.h"

int					hash(char *str)
{
	int				code;
	int				len;
	int				i;

	len = ft_strlen(str);
	code = 7;
	i = 0;
	while (i < len)
	{
		code = str[i] + 31 * code;
		i++;
	}
	return (code % 1000);
}

void		put_link(t_room *room)
{
	t_link	*l;

	l = room->lst;
	while (l)
	{
		ft_putstr(l->room->name);
		ft_putstr("->");
		l = l->next;
	}
	ft_putendl(NULL);
}

int			main()
{
	t_lem	*lem;

	if ((lem = parse()) && lem->start && lem->end)
	{
		lem->end->dist = 0;
		lem->start->lem = 1;
		way(lem->end, lem);
		sort(lem->tab);
		if (lem->start->dist < 1000)
			return (lemin(lem));
	}
	ft_putstr("ERROR\n");
	del_lem(&lem);
	return (0);
}
