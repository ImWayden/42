/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 12:06:00 by msarr             #+#    #+#             */
/*   Updated: 2014/06/25 12:06:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_deltab(char ***str)
{
	char		**tab;
	int			i;

	if (str && *str)
	{
		tab = *str;
		i = 0;
		while (tab && tab[i])
		{
			ft_memdel((void **)&(tab[i]));
			i++;
		}
		ft_memdel((void **)str);
	}
}
