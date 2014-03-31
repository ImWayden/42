/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:42:45 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 14:29:21 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = 0;
	while (i++ < n)
	{
		if (*tmp2 == c)
		{
			*tmp1++ = *tmp2++;
			return (tmp1);
		}
		*tmp1++ = *tmp2++;
	}
	return (NULL);
}
