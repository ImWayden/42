/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:34:22 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:34:24 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			**ft_tabdup(char **tab)
{
	int			i;
	char		**dup;

	i = 0;
	dup = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (dup && tab && tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dup);
}
