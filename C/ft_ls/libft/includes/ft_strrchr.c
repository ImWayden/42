/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 14:52:35 by msarr             #+#    #+#             */
/*   Updated: 2013/11/24 14:52:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	
	tmp = (char *)s + ft_strlen(s);
	while (*tmp != (char) c && s)
	{
		if (tmp == s)
			return (NULL);
		tmp--;
	}
	return (tmp);
}
