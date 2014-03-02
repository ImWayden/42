/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:49:19 by msarr             #+#    #+#             */
/*   Updated: 2013/11/24 17:49:24 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	if ((tmp1 <= tmp2 || tmp1 >= tmp2 + n) && tmp1 && tmp2)
		return (ft_memcpy(s1,s2,n));
	else
	{
		n--;
		while (tmp1[n] && tmp2[n] && tmp1 && tmp2)
		{
			tmp1[n] = tmp2[n];
			n--;
		}
	}
	return (s1);
}
