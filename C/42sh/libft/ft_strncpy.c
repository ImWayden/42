/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/18 04:56:43 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:32:59 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*p;

	p = dest;
	while ((n != 0) && (*dest = *src) && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 1)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (p);
}
