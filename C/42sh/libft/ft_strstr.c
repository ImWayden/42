/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:26:48 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:33:55 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	a;

	a = ft_strlen(s2);
	if (a == 0)
		return ((char*)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, a))
			s1++;
		else
			return ((char *)s1);
	}
	return (NULL);
}
