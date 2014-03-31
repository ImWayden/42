/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:46:20 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:47:38 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = s;
	if (!s || !c)
		return (NULL);
	while (i < n && *str)
	{
		if (*str == c)
			return ((void *)str);
		i++;
		str++;
	}
	if (i < n && *str == '\0' && c == '\0')
		return ((void *)str);
	return (NULL);
}
