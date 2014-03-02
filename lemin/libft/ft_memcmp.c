/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:15:16 by msarr             #+#    #+#             */
/*   Updated: 2013/11/25 18:15:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *) s1;
	tmp2 = (char *) s2;
	while (*tmp1 && *tmp2 && n)
	{
		if (*tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		else
			return (*tmp1 - *tmp2);
		n--;
	}
	if (n == 0)
		return (0);
	else
		return(*tmp1 - *tmp2);
}
