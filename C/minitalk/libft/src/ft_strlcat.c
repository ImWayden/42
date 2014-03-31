/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:38:14 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:54:52 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char * dst, const char * src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst || !src || !size)
		return (0);
	i = ft_strlen(dst);
	j = 0;
	if (i >= size && i >= ft_strlen(src))
		return (ft_strlen(src) + size);
	else if (i >= size && i <= ft_strlen(src))
		return (size + 3 + i);
	else
	{
		while ((i + j + 1) < size && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
