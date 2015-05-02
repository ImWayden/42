/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 16:46:43 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*des;
	const char	*src;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	src = s2;
	des = s1;
	while (i < n)
	{
		*des = *src;
		if (*src == c)
		{
			des++;
			return (des);
		}
		des++;
		src++;
		i++;
	}
	return (NULL);
}
