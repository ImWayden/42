/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:00:14 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:05:44 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *s1, char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)))
			s1++;
		else
			return ((char *)s1);
	}
	return (NULL);
}
