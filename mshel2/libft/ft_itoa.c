/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 21:04:07 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/21 19:16:26 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(int n)
{
	size_t			len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static size_t		ft_int_neg_len(int n)
{
	size_t			len;

	len = 2;
	while (n <= -(10))
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char			*ft_itoa_neg(int n)
{
	char			*str;
	size_t			len;

	len = ft_int_neg_len(n);
	str = (char *) malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n <= (-1))
	{
		str[len - 1] = (-(n % (-10)) + '0');
		len--;
		n /= 10;
	}
	str[0] = '-';
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	size_t			len;

	if (n < 0)
		return (ft_itoa_neg(n));
	len = ft_intlen(n);
	str = (char *) malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n >= 1)
	{
		str[len - 1] = (n % 10 + '0');
		len--;
		n /= 10;
	}
	return (str);
}
