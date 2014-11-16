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

#include "getline.h"

static int		delete_beg(char *buf, char **str, int i)
{
	if (buf[0] == 127 && (*str)[i])
		ft_putstr(tgetstr("le", NULL));
	else if ((*str)[i])
		ft_putstr(tgetstr("nd", NULL));
	ft_putstr(tgetstr("ce", NULL));
	return (1);
}

static int		delete_end(int k, char *buf)
{
	while (k > 0 && buf[0] == 127)
	{
		ft_putstr(tgetstr("le", NULL));
		k--;
	}
	while (k >= 0 && buf[0] == 27)
	{
		ft_putstr(tgetstr("le", NULL));
		k--;
	}
	return (1);
}

int				delete_mode(char **str, char *buf, int j)
{
	int			i;
	int			k;

	i = ft_strlen(*str);
	if (*str && j > 0 && j <= i)
	{
		i = i - j;
		delete_beg(buf, str, i);
		k = -1;
		while ((*str)[i])
		{
			(*str)[i] = (*str)[i + 1];
			ft_putchar((*str)[i]);
			i++;
			k++;
		}
		delete_end(k, buf);
		return (-1);
	}
	return (0);
}
