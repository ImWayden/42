/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:42:27 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 22:19:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_recup(char **str, t_select **list)
{
	int		i;

	*list = NULL;
	i = 0;
	while (str && str[i])
	{
		*list = ft_addlist(*list, str[i], i);
		i++;
	}
	if (*list)
		(*list)->curseur = 'y';
	return (i);
}
