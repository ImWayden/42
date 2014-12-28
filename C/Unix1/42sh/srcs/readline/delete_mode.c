/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 20:16:23 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 12:01:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				delete_mode(char **str, int j, char *buf)
{
	int			i;
	int			k;

	ft_putstr(tgetstr("dm", NULL));
	k = 0;
	if (K_DEL(buf) && j <= ft_strlen(*str))
	{
		ft_putstr(tgetstr("le", NULL));
		ft_putstr(tgetstr("dc", NULL));
	}
	else if (K_BDEL(buf) && j > 0)
	{
		ft_putstr(tgetstr("nd", NULL));
		ft_putstr(tgetstr("dc", NULL));
		ft_putstr(tgetstr("le", NULL));
		k = -1;
	}
	ft_putstr(tgetstr("ed", NULL));
	i = ft_strlen(*str) - j;
	while (i >= 0 && (*str)[i])
	{
		(*str)[i] = (*str)[i + 1];
		i++;
	}
	return (k);
}
