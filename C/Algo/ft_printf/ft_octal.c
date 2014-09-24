/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:20:48 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 18:20:51 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(long n)
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

char		*ft_octal(long n)
{
	char		*str;
	int			i;
	size_t		len;

	i = 0;
	len = ft_intlen(n);
	str = ft_strnew(len + 1);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[i] = ((n % 8) + '0');
		n = n / 8;
		i++;
	}
	str = ft_strreverse(str);
	str[i] = '\0';
	return (str);
}
