/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:05:35 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/25 15:10:28 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*x;
	char	*y;

	x = dest;
	y = (char*)src;
	while (n != 0)
	{
		*x++ = *y++;
		n--;
	}
	return (dest);
}
