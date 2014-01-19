/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:09:42 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/24 22:53:53 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*x;
	char	*y;

	x = dest;
	y = (char *)src;
	if (y < x)
	{
		while (n != 0)
		{
			n--;
			x[n] = y[n];
		}
	}
	else
	{
		while (n != 0)
		{
			*x++ = *y++;
			n--;
		}
	}
	return (dest);
}
