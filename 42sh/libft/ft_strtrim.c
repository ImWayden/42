/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:00:16 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:08:13 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strtrim(char const *s)
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
