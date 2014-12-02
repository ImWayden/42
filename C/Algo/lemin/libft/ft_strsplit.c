/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:25:10 by msarr             #+#    #+#             */
/*   Updated: 2014/03/03 00:09:57 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		**ft_array(char *s, char c)
{
	size_t		j;
	char		**split;

	j = 0;
	split = NULL;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			j++;
		while (*s && *s != c)
			s++;
	}
	if ((j) && (split = (char **)malloc(sizeof(char *) * (j + 1))))
		split[j] = NULL;
	return (split);
}

char			*ft_split(char *str, int *c)
{
	int			i;

	while (str && *str == *c)
		str++;
	i = 0;
	while (str && str[i] && str[i] != *c)
		i++;
	*c = i;
	return (str);
}

char			**ft_strsplit(char const *s, int c)
{
	char		**split;
	char		*str;
	int			j;
	int			i;

	i = 0;
	str = (char *)s;
	split = ft_array((char *)str, c);
	while (split && str && *str)
	{
		j = c;
		str = ft_split((char *)str, &j);
		if (j)
			split[i] = ft_strsub(str, 0, j);
		str = str + j;
		i++;
	}
	return (split);
}
