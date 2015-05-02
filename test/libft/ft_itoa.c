/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 16:53:48 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char				*ft_itoa(int n)
{
	char	*ret;
	int		i;
	size_t	len;
	char	sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = 2 + (n < 0);
	i = n;
	while ((n = n / 10))
		len++;
	n = i;
	if ((ret = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[len] = '-';
	return (ret);
}
