/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:55:16 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:55:46 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n;

	i = 0;
	n = (char *)malloc(ft_strlen(s) + 1);
	if (!s || !f || !n)
		return (NULL);
	while (*s)
	{
		n[i] = (*f)(i, *s);
		i++;
		s++;
	}
	n[i] = '\0';
	return (n);
}
