/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:49:13 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:13:28 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*x;
	int		i;

	i = 0;
	if (s)
	{
		x = (char *)ft_memalloc(len + 1);
		while (len--)
		{
			x[i] = s[start + i];
			i++;
		}
		return ((char*)x);
	}
	return (NULL);
}
