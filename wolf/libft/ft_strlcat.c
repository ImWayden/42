/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:24:17 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:11:00 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		ldest;
	size_t		lsrc;
	size_t		x;
	size_t		y;
	size_t		z;

	ldest = ft_strlen(dest);
	lsrc = ft_strlen((char*)src);
	x = 0;
	y = ldest;
	z = size - ldest - 1;
	if (size > ldest)
	{
		while (x < z)
		{
			dest[y] = src[x];
			x++;
			y++;
		}
		dest[y] = '\0';
		return (ldest + lsrc);
	}
	return (lsrc + size);
}
