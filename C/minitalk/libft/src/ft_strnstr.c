/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 00:29:24 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:57:09 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (n && *s1)
	{
		i = 0;
		while (*(s1 + i) == s2[i] && n--)
		{
			i++;
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
