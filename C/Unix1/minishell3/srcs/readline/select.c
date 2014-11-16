/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:23:13 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 22:50:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

t_line			*setlist(t_line *list)
{
	t_line		*tmp;
	struct winsize	mywin;
	int				i;
	int				j;
	int				k;

	tmp = list;
	i = 0;
	while (tmp)
	{
		if (i < ft_strlen(tmp->str))
			i = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	i += 2;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
	while (list)
	{
		k = ft_strlen(list->str);
		ft_putstr(list->str);
		while (k < i)
		{
			ft_putchar(' ');
			k++;
		}
		j += k;
		if (j + i > mywin.ws_col && !(j = 0))
			ft_putendl(NULL);
		list = list->next;
		k = 0;
	}
	return (list);
}