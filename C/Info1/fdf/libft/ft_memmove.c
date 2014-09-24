/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:35:04 by sraccah          ###   ########.fr       */
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
