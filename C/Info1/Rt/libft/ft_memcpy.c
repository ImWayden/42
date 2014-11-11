/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 14:28:36 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:01:07 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	if ((int)n < 0 || n > ft_strlen(s1) + 1)
	{
		return (NULL);
	}
	while (n && *(char *)s1)
	{
		*(char *)s1++ = *(char *)s2++;
		n--;
	}
	if (n != 0)
		*(char *)s1 = *(char *)s2;
	return (s1);
}
