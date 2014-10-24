/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:41:15 by msarr             #+#    #+#             */
/*   Updated: 2014/10/14 00:27:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			settinglist(t_select *list, int j, struct winsize mywin)
{
	int				i;
	int				k;
	t_select		*tmp;

	k = 0;
	while (list && list->prev->pos < list->pos)
		list = list->prev;
	tmp = list;
	while (tmp)
	{
		i = 0;
		while (i < mywin.ws_row)
		{
			tmp->row = i;
			tmp->col = k * mywin.ws_col / j;
			if ((tmp = tmp->next) == list)
				return ;
			i++;
		}
		k++;
	}
}

t_select			*ft_setlist(t_select *list, int argc)
{
	int				j;
	struct winsize	mywin;
	int				i;

	if (list)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
		i = argc;
		j = 1;
		mywin.ws_row--;
		if (i > mywin.ws_row)
			while ((j * mywin.ws_row) < i && mywin.ws_row)
				j++;
		settinglist(list, j, mywin);
	}
	return (list);
}
