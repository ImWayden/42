/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:54:28 by sraccah           #+#    #+#             */
/*   Updated: 2013/11/25 10:54:29 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char				*ft_strncat(char *dest, const char *src, size_t n)
{
	int				i;
	unsigned int	a;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	while (a < n)
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	dest[i] = '\0';
	return (dest);
}
