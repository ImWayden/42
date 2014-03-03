/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:55:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 19:25:57 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (*tmp1 && *tmp2 && n-- && *(tmp2 - 1) != c)
		*tmp1++ = *tmp2++;
	if (*(tmp2 - 1) != c)
		return (NULL);
	return (tmp1);
}
