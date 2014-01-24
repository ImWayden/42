/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:07:45 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/25 15:10:09 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*x;
	char	*y;
	int		i;

	x = dest;
	y = (char*)src;
	i = 0;
	while (n != 0)
	{
		*x++ = i = *y++;
		if (i == c)
			return (x);
		n--;
	}
	return (NULL);
}
