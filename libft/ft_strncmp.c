/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:53:24 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 12:53:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *tmp1;
	char *tmp2;

	tmp1 = (char *) s1;
	tmp2 = (char *) s2;
	while (*tmp1 && *tmp2 && n)
	{
		if (*tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
			n--;
		}
		else
			return (*tmp1 - *tmp2);
	}
	if (!n)
		return (0);
	else
		return (*tmp1 - *tmp2);
}
