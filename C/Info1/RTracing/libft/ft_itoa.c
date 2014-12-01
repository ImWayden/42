/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/15 15:49:28 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

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

char			*ft_itoa(int n)
{
	char		*str;
	char		c;
	int			i;
	size_t		len;

	i = 0;
	len = ft_intlen(n);
	str = ft_strnew(len + 1);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[len - 1] = '-';
	while (n)
	{
		if (n < 0)
			c = (n % 10) * -1 + '0';
		else
			c = n % 10 + '0';
		n = n / 10;
		str[i] = c;
		i++;
	}
	str = ft_strreverse(str);
	str[len] = '\0';
	return (str);
}
