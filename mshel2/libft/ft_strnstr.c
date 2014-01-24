/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:48:07 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:12:52 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	if (len2 == 0)
		return ((char *)s1);
	if ((i = n - len2 + 1) > (int)len1)
		i = len1 - len2 + 1;
	if (n > len2)
		n = len2;
	while (i > 0)
	{
		if (ft_strncmp(s1, s2, n) == 0)
			return ((char *)s1);
		s1++;
		i--;
	}
	return (NULL);
}
