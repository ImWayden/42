/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 10:36:11 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 10:51:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(src);
	j = 0;
	str = NULL;
	if (i)
	{
		str = (char *)malloc(sizeof(*src) * (i + 1));
		if (str != NULL)
		{
			str[i] = '\0';
			while (j < i)
			{
				str[j] = src[j];
				j++;
			}
		}
	}
	return (str);
}
