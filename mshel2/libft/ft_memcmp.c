/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:13:42 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/25 15:11:09 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*x;
	char	*y;

	x = (char*)s1;
	y = (char*)s2;
	while (n != 0 && *x == *y)
	{
		x++;
		y++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*x - *y);
}
