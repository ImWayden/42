/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:03:59 by msarr             #+#    #+#             */
/*   Updated: 2014/03/03 00:12:54 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_intlen(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while ((n = n / 10))
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		j;
	char	*str;

	j = ft_intlen(n);
	str = ft_strnew(j);
	if (n < 0)
		*str = '-';
	if (!n)
		*str = '0';
	while (str && n && j)
	{
		j--;
		str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
