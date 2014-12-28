/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 11:01:38 by msarr             #+#    #+#             */
/*   Updated: 2014/12/27 23:49:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "42sh.h"

int			is_quot(char c)
{
	if (c == '\'' || c == '\"' || c == '\\')
		return (1);
	return (0);
}

int			find_next(char *str)
{
	int		c;
	int		i;

	i = 1;
	c = str[0];
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c ? i : 0);
}

int			quot(t_shell *shell, char **line)
{
	char	*str;
	int		i;

	str = *line;
	while (*str)
	{
		if(is_quot(*str))
		{
			if(!(i = find_next(str)))
			{
				ft_putstr("~>");
				str = get_line(shell, 1);
				ft_join(line, str);
				ft_memdel((void **)&str);
				return (0);
			}
			else
				str += i;
		}
		str++;
	}
	return (1);
}