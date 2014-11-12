/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/11 15:00:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

int					ft_put(t_shell *shell, char *str, int i)
{
	int				j;

	j = 0;
	if (i < 0)
		i = 0;
	if (i > ft_strlen(str))
		i = ft_strlen(str);
	ft_termcaps();
	ft_prompt(shell);
	while (str[j])
	{
		if (j == i)
			ft_cursor(str[j]);
		else
			ft_putchar(str[j]);
		j++;
	}
	if (j == i)
		ft_cursor(' ');
	return (i);
}

int					term_center(char *str)
{
	if (str[0] == '\t')
		str[0] = ' ';
	else if (str[0] == 27)
	{
		if (str[1] == 91 && str[2] == 'C')
			return (1);
		if (str[1] == 91 && str[2] == 'D')
			return (-1);
	}
	return (0); 
}

int					ft_term(t_shell *shell, char **str)
{
	int				j;
	char			*buf;

	buf = *str;
	j = 0;
	ft_putstr(tgetstr("sc", NULL));
	ft_prompt(shell);
	while ((read(0, buf, 4)))
	{
		if (ft_isprint(buf[0]))
		{
			buf += 1;
			*buf = '\0';
			j++;
		}
		else if (buf[0] != '\n')
		{
			j += term_center(&(buf[0]));
			buf[0] = '\0';
		}
		else
		{
			buf[0] = '\0';
			ft_putendl(NULL);
			return (1);
		}
		j = ft_put(shell, *str, j);
	}
	return (1);
}