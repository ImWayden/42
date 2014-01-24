/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:46:04 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/28 19:44:08 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		n;

	n = ft_strlen((char*)s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, n))
			s1++;
		else
			return ((char*)s1);
	}
	return (0);
}
