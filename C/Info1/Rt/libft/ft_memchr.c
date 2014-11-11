/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 22:52:56 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:00:50 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*tmp;

	i = 0;
	tmp = s;
	while (i++ < n)
	{
		if (*tmp == c)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
