/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 06:22:40 by msarr             #+#    #+#             */
/*   Updated: 2013/12/31 06:22:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (i + j + 1));
	if (str)
		str[i + j] = '\0';
	else
		return (NULL);
	while (j--)
		str[i + j] = s2[j];
	while (i--)
		str[i] = s1[i];
	return (str);
}
