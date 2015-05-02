/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:37:33 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int					ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	a = 0;
	destlen = ft_strlen(dest);
	b = destlen;
	srclen = ft_strlen(src);
	i = n - destlen - 1;
	if (n > destlen)
	{
		while (a < i)
		{
			dest[b] = src[a];
			a++;
			b++;
		}
		dest[b] = '\0';
		return (srclen + destlen);
	}
	return (srclen + n);
}
