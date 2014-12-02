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
	size_t	t_dest;
	size_t	t_src;
	size_t	i;
	size_t	j;
	size_t	k;

	t_dest = ft_strlen(dest);
	t_src = ft_strlen((char*)src);
	i = 0;
	j = t_dest;
	k = size - t_dest - 1;
	if (size > t_dest)
	{
		while (i < k)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
		return (t_dest + t_src);
	}
	return (t_src + size);
}
