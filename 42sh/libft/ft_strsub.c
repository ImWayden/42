/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:05:48 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/06 21:40:20 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str)
		str[len] = '\0';
	else
		return (NULL);
	i = 0;
	while (s[start] && i < (int)len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
