/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:07:57 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 13:34:59 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n && tmp)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		else
			tmp++;
		n--;
	}
	return (NULL);
}
