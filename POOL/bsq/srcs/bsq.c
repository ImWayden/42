/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 18:00:29 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 18:00:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "bsq.h"

int			bsq(t_list *list, int x_y, int c, int c_max, int l_max)
{
	t_list		*tmp;
	int			i;
	int			j;

	ft_putendl("start");
	ft_putnbr(x_y);
	ft_putnbr(c);
	ft_putendl("");
	if (x_y == c_max * l_max)
		return (-1);
	i = x_y / l_max;
	j = x_y % l_max;
	if (c_max - i < c || l_max - j < c)
		return (-1);
	else
	{
		tmp = list;
		while (tmp)
		{
			if (tmp->i >= i && tmp->i < i + c && tmp->j >= j && tmp->j < j + c)
				return (bsq(list, ++x_y, c, c_max, l_max));
			tmp = tmp->next;
		}
		return (x_y);
	}
}
