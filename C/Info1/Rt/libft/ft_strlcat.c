/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:11:39 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:04:18 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	n_1;
	size_t	n_2;
	size_t	count;
	size_t	lens1;
	size_t	lens2;

	n_1 = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	n_2 = lens1;
	count = n - lens1 - 1;
	if (n > lens1)
	{
		while (n_1 < count)
		{
			s1[n_2] = s2[n_1];
			n_1++;
			n_2++;
		}
		s1[n_2] = '\0';
		return (lens2 + lens1);
	}
	return (lens2 + n);
}
