/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:20:06 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/25 15:05:21 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*x;
	char	*y;
	char	z;

	x = dest;
	y = (char*)src;
	while (*x)
		x++;
	while (n > 0 && *y)
	{
		*x++ = z = *y++;
		if (z == '\0')
			return (dest);
		n--;
	}
	if (z)
		*x = '\0';
	return (dest);
}
