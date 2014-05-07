/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:41:15 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:41:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_selectlist		*settinglist(t_selectlist *list, int j,
									struct winsize mywin)
{
	int					i;
	int					k;
	t_selectlist		*tmp;

	k = 0;
	i = 0;
	tmp = list;
	tmp->row = k;
	tmp->col = k;
	i++;
	tmp = tmp->next;
	while (tmp && tmp != list)
	{
		while (i < mywin.ws_row && tmp != list)
		{
			tmp->row = i;
			tmp->col = k * mywin.ws_col / j;
			tmp = tmp->next;
			i++;
		}
		i = 0;
		k++;
	}
	return (list);
}

t_selectlist			*ft_setlist(t_selectlist *list)
{
	int					j;
	struct winsize		mywin;
	int					i;

	if (list)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
		i = ft_selectlistlen(list);
		j = 1;
		if (i > mywin.ws_row)
			while ((j * mywin.ws_row) < i && mywin.ws_row)
				j++;
		return (settinglist(list, j, mywin));
	}
	return (list);
}
