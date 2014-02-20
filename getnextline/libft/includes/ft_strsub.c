/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:40:58 by msarr             #+#    #+#             */
/*   Updated: 2013/11/27 11:41:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (str)
		str[len] = '\0';
	else
		return (NULL);
	i = 0;
	
	while (s[start] && i < (int) len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
