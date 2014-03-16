/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 01:47:23 by msarr             #+#    #+#             */
/*   Updated: 2014/03/14 01:47:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				deltab(char ***str)
{
	int 			i;
	char			**tab;

	tab = *str;
	i = 0;
	while(tab && tab[i])
	{
		ft_memdel((void **)&(tab[i]));
		i++;
	}
	ft_memdel((void **)&(*str));
	*str = NULL;
}
