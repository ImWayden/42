/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:48:39 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 12:48:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char *tmp1;
	char *tmp2;

	tmp1 = (char *) s1;
	tmp2 = (char *) s2;
	while (*tmp1 && *tmp2)
	{
		if (*tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		else
			return (*tmp1 - *tmp2);
	}
	return (*tmp1 - *tmp2);
}
