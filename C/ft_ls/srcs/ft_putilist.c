/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putilist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:32 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:51:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void	ft_putilist(t_list *list, char *dir)
{
	t_list *tmp;
	struct stat test;
	
	tmp = list;
	while (tmp)
	{
		stat(ft_strjoin(ft_strjoin(dir, "/"), tmp->str), &test);
		ft_putinfos(test);
		ft_putstr(tmp->str);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}
