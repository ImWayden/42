/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:02:08 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:13:48 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*x;
	int		i;
	int		j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen((char *)s) - 1;
    while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
        j--;
	if (j < 0)
	{
		x = (char*)malloc(sizeof(*x));
		x[0] = '\0';
		return (x);
	}
	x = (char *)malloc(sizeof(*x) * (j - i + 1));
	if (x == 0)
		return (NULL);
	x = ft_strsub(s, i, (j - i + 1));
	return ((char*)x);
}
