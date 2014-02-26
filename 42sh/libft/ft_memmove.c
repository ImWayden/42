/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:51:59 by sraccah           #+#    #+#             */
/*   Updated: 2013/11/25 10:51:59 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char *)src;
	if (src != dest)
	{
		if (src > dest)
		{
			while (n--)
				*d++ = *s++;
		}
		else
		{
			d += n - 1;
			s += n - 1;
			while (n--)
				*d-- = *s--;
		}
	}
	return (dest);
}
