/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:51:18 by sraccah           #+#    #+#             */
/*   Updated: 2013/11/25 10:51:19 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;
	char		p;

	d = dest;
	s = src;
	while (n--)
	{
		*d++ = p = *s++;
		if (p == (char)c)
			return (d);
	}
	return (NULL);
}
