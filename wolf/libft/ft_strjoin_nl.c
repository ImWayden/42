/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 21:14:01 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/18 21:22:55 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"libft.h"

char				*ft_strjoin_nl(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*dest;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(dest = (char *)malloc
		  ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
