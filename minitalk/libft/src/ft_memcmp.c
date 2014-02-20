/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:53:15 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:47:53 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*a;
	const char	*b;

	if (!s1 && !s2 && !n)
		return (0);
	i = 0;
	a = s1;
	b = s2;
	while (i < n)
	{
		if (*a > *b)
			return (*a - *b);
		else if (*a < *b)
			return (*a - *b);
		i++;
		a++;
		b++;
	}
	return (0);
}
