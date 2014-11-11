/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:44:59 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:05:50 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)ft_memalloc(len + 1);
	if (s)
	{
		while (len--)
		{
			tmp[i] = s[start + i];
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
