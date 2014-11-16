/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 22:02:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

int					term_center(char *str, int j, int len)
{
	if (str[0] == 27)
	{
		if (str[1] == 91 && str[2] == 'C' && j > 0)
		{
			ft_putstr(tgetstr("nd", NULL));
			return (-1);
		}
		if (str[1] == 91 && str[2] == 'D' && j < len)
		{
			ft_putstr(tgetstr("le", NULL));
			return (1);
		}
	}
	return (0); 
}

int					ft_term(char **str, t_shell *shell)
{
	int				j;
	char			buf[4];

	j = 0;
	ft_bzero(buf, 4);
	while ((read(0, buf, 4)))
	{
		if (buf[0] == '\t')
			autoimpl(str, shell, j);
		else if (ft_isprint(buf[0]) && buf[0] != '^' && j > 0)
			insert_mode(str, j, buf[0]);
		else if (buf[0] == 127)
			delete_mode(str, buf, j + 1);
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == '3')
			j += delete_mode(str, buf, j - 1);
		else if (ft_isprint(buf[0]) && buf[0] != '^')
		{
			ft_putchar(*buf);
			*str = ft_strjoin(*str, buf);
		}
		else if (buf[0] != '\n')
			j += term_center(&(buf[0]), j, ft_strlen(*str));
		else
		{
			ft_putendl(NULL);
			return (1);
		}
		ft_bzero(buf, 4);
	}
	return (1);
}