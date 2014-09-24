/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:35:07 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	char			*ps;
	unsigned int	i;

	ps = (char *)s;
	i = 0;
	while (i < n)
	{
		*ps++ = (unsigned char)c;
		i++;
	}
	return (s);
}
