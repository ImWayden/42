/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:19:01 by sraccah           #+#    #+#             */
/*   Updated: 2013/11/25 16:19:01 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strnstr(const char *dest, const char *src, size_t n)
{
	int		i;

	if (ft_strlen(src) == 0)
		return ((char *)dest);
	if ((i = n - ft_strlen(src) + 1) > (int)ft_strlen(dest))
		i = ft_strlen(dest) - ft_strlen(src) + 1;
	if (n > ft_strlen(src))
		n = ft_strlen(src);
	while (i-- > 0)
	{
		if (ft_strncmp(dest, src, n) == 0)
			return ((char *)dest);
		dest++;
	}
	return (NULL);
}
