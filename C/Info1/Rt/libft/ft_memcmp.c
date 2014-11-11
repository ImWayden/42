/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 14:53:50 by atouzeau          #+#    #+#             */
/*   Updated: 2014/04/25 18:10:19 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*tmp;
	const char	*tmp2;
	int			i;

	i = 0;
	tmp = s1;
	tmp2 = s2;
	if (n == 0)
		return (0);
	n--;
	while (n && tmp[i] == tmp2[i] && tmp[i] && tmp2[i])
	{
		i++;
		n--;
	}
	if (tmp[i] == '\0' && tmp2[i] != '\0')
		return (-tmp2[i]);
	if (tmp2[i] == '\0' && tmp[i] != '\0')
		return (tmp[i]);
	if (tmp[i] < tmp2[i])
		return (-1);
	if (tmp[i] > tmp2[i])
		return (1);
	return (0);
}
