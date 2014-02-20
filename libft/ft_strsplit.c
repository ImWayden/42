/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:25:10 by msarr             #+#    #+#             */
/*   Updated: 2013/11/27 14:25:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_Word_Number(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static char		**ft_Malloc(size_t x)
{
	char		**split;

	split = (char **)malloc(sizeof(char *) * (x + 1));
	if (split == 0)
		return (NULL);
	ft_bzero(split, x);
	return (split);
}

char	**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		x;
	size_t		y;
	size_t		z;
	size_t		n;

	x = ft_Word_Number(s, c);
	n = 0;
	y = 0;
	split = ft_Malloc(x + 1);
	while (s[y])
	{
		z = 0;
		while (s[y] == c && s[y])
			y++;
		z = y;
		while (s[y] != c && s[y])
			y++;
		if (n != x)
		{
			split[n] = ft_strsub(s, z, (y - z));
			n++;
		}
	}
	split[n] = '\0';
	return (split);
}
