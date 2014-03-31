/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:20:57 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 20:21:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(size_t n)
{
	size_t		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

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
