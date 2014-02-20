/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:42:27 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:42:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*ft_recup(char *str)
{
	int		i;
	t_list	*list;

	list = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			while (!ft_isalpha(str[i]))
				i++;
			if (str[i] == 's'|| str[i] == 'i' || str[i] == 'd'
				|| str[i] == 'c' || str[i] == 'x' || str[i] == 'o'
				|| str[i] == 'p')
			list = ft_add_list(list, str, i);
		}
		i++;
	}
	return (list);
}
