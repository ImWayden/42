/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 00:01:41 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/19 00:01:46 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrd_nbr(char const *s, char c);
static char		**ft_tab_ptr(size_t nb);
static char		**ft_malloc_ptr(char **tab, char const *s, char c, size_t nb);

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	nb;
	char			**tab;

	nb = ft_wrd_nbr(s, c);
	tab = ft_tab_ptr(nb);
	tab = ft_malloc_ptr(tab, s, c, nb);
	return (tab);
}

static int		ft_wrd_nbr(char const *s, char c)
{
	unsigned int	i;
	unsigned int	wrd_nbr;

	i = 0;
	wrd_nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			wrd_nbr++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wrd_nbr);
}

static char		**ft_tab_ptr(size_t nb)
{
	char	**tab;

	tab = (char **) malloc(sizeof(char *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

static char		**ft_malloc_ptr(char **tab, char const *s, char c, size_t nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < nb)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[k] = ft_strsub(s, j, (i - j));
		k++;
	}
	tab[k] = ft_strnew(1);
	return (tab);
}
