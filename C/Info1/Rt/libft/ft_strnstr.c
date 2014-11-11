/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:01:38 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:05:26 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	int		index;

	if (*s2 == '\0')
		return ((char *)s1);
	if ((index = n - ft_strlen(s2) + 1) > (int)ft_strlen(s1))
		index = ft_strlen(s1) - ft_strlen(s2) + 1;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2);
	while (index > 0)
	{
		if (ft_strncmp(s1, s2, n) == 0)
			return ((char *)s1);
		s1++;
		index--;
	}
	return (NULL);
}
