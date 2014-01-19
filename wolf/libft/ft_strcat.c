/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:16:00 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/24 23:14:52 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *dest, const char *src)
{
	char	*x;
	char	*y;

	x = dest;
	y = (char*)src;
	while (*x)
		x++;
	while ((*x = *y))
		*x++ = *y++;
	return (dest);
}
