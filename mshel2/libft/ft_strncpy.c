/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:51:35 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/21 18:55:26 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*cpy;

	cpy = dest;
	while ((n != 0) && (*dest = *src))
	{
		dest++;
		src++;
		n--;
	}
	while (n > 1)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (cpy);
}
