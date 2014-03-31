/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 14:28:18 by msarr             #+#    #+#             */
/*   Updated: 2013/11/24 14:28:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, char *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	
	if (!s1 || !s2 )
			return (NULL);
	else if (!n)
		return (s1); 
	else
	{
		tmp1 = s1;
		tmp2 = s2;
		while (*tmp2 && n && tmp1)
		{
			*tmp1++ = *tmp2++;
			n--;
		}
		while (tmp1 && n)
		{
			*tmp1++ = '\0';
			n--;
		}
	}
	return (s1);
}
