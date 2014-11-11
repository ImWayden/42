/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:14:21 by atouzeau          #+#    #+#             */
/*   Updated: 2014/03/22 19:31:25 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sncpy(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	**ft_strsplit(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(*tab) * (ft_strlen(str) / 2 + 2));
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i != j)
		{
			tab[k] = malloc(sizeof(**tab) * (i - j + 1));
			ft_sncpy(tab[k], &str[j], i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
