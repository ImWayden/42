/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:05:03 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:58:32 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*n;

	i = 0;
	if (!s)
		return (NULL);
	n = (char *)malloc(sizeof(char *) * len);
	if (!n)
		return (NULL);
	else
	{
		while (i < len)
		{
			n[i] = s[start];
			i++;
			start++;
		}
		n[i] = '\0';
	}
	return (n);
}
