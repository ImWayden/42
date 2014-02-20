/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:24:13 by msarr             #+#    #+#             */
/*   Updated: 2013/11/27 12:24:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

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

char	*ft_strnjoin(char *s1, char c, int n)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = 0;
	str = (char *) malloc(sizeof(char) * (i + 2));
	if (str)
		str[i + 1] = '\0';
	else
		return (NULL);
	k = i - n;
	i = 0;
	str[k] = c;
	while (s1[i])
	{
		if (j != k)
			str[j] = s1[i];
		else
			i--;
		i++;
		j++;
	}
	return (str);
}

char	*ft_join(char *s1, char *s2, int i)
{
	if (i < 0)
		i = i * -1;
	if (!i || !(*s2))
		return (ft_strjoin(s1, s2));
	else
		return (ft_strnjoin(s1, *s2, i));
}
