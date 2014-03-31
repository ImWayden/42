/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:35:28 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:48:38 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*src;
	char	*dst;

	src = (char *)s2;
	dst = s1;
	if (src > dst)
		ft_memcpy(dst, src, n);
	else
	{
		while (n > 0)
		{
			dst[n - 1] = src[n - 1];
			n--;
		}
	}
	return (s1);
}
