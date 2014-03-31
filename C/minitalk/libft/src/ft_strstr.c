/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:25 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:58:15 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (*s1 != '\0')
	{
		i = 0;
		j = 0;
		while (*(s1 + j) == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
