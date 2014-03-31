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


t_list		*ft_setlist(t_list *list)
{
	int		j;
	int		k;
	struct winsize mywin;
	int				i;
	t_list			*tmp;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
	i = ft_listlen(list);
	j = 1;
	if (i > mywin.ws_row)
		while ((j * mywin.ws_row) < i && mywin.ws_row)
			j++;
	k = 0;
	i = 0;
	tmp = list;
	tmp->row = k;
	tmp->col = k;
	i++;
	tmp = tmp->next;
	while (tmp != list)
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
