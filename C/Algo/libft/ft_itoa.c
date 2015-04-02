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

#include "libft.h"

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
	int		s;
	char	*str;

	j = ft_intlen(n);
	str = ft_strnew(j);
	s = 1;
	if (n < 0 && (s = -1))
		*str = '-';
	if (!n)
		*str = '0';
	while (str && n)
	{
		str[--j] = s * (n % 10) + '0';
		n = n / 10;
	}
	ft_putendl(str);
	return (str);
}
