/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:37:53 by sraccah          ###   ########.fr       */
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
