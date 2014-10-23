/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:20:57 by msarr             #+#    #+#             */
/*   Updated: 2014/10/22 15:33:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hexa(size_t n)
{
	char		*str;
	int			i;
	size_t		len;
	char		*str1;

	i = 0;
	len = ft_intlen(n);
	str = ft_strnew(len + 1);
	str1 = "0123456789abcdef";
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = str1[(n % 16)];
		n = n / 16;
		i++;
	}
	str[len] = '\0';
	str = ft_strreverse(str);
	str[len] = '\0';
	return (str);
}
