/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:31:24 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:55:27 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*n;

	i = 0;
	if (!s || !f)
		return (NULL);
	n = (char *)malloc(ft_strlen(s));
	if (n)
	{
		while (*s)
		{
			n[i] = (*f)(*s);
			i++;
			s++;
		}
		n[i] = '\0';
		return (n);
	}
	return (NULL);
}
