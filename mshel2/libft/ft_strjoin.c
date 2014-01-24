/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:07:42 by xmachado          #+#    #+#             */
/*   Updated: 2013/11/27 20:31:00 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
		x = (char *)ft_memalloc(len + 1);
		if (x == 0)
			return (NULL);
		while (s1[i])
		{
			x[i] = s1[i];
			i++;
		}
		while (s2[j])
			x[i++] = s2[j++];
		x[i] = '\0';
		return (x);
	}
	return (NULL);
}
