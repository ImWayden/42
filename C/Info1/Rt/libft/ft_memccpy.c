/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:39:16 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:00:25 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	if ((int)n < 0 || ft_strlen(s2) > n)
		return (NULL);
	while (n)
	{
		*(char *)s1++ = *(char *)s2++;
		if (*(char *)s2 == c)
		{
			*(char *)s1 = *(char *)s2;
			return (s1);
		}
		n--;
	}
	return (NULL);
}
