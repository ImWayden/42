/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:24:35 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 14:23:32 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	tmp1;
	size_t	tmp2;
	size_t	i;
	size_t	j;
	size_t	k;

	tmp1 = ft_strlen(dest);
	tmp2 = ft_strlen((char*)src);
	i = 0;
	j = tmp1;
	k = size - tmp1 - 1;
	if (size > tmp1)
	{
		while (i < k)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
		return (tmp1 + tmp2);
	}
	return (tmp2 + size);
}
