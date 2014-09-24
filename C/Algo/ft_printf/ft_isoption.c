/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:41:39 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:41:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isoption(char *str, t_list *list)
{
	if (list && *str != '%')
	{
		while (!ft_isalpha(*str))
			str++;
		if (list->name == *str)
			return (1);
	}
	return (0);
}
