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
#include "shell.h"

int			is_quot(char *str, int i)
{
	if ((str[i] == '\'' || str[i] == '\"' || str[i] == '\\')
		&& (!i || str[i - 1] != '\\'))
		return (1);
	return (0);
}

int			find_next(char *str)
{
	int		c;
	int		i;

	i = 1;
	c = str[0];
	while (str[i] && (str[i] != c || !is_quot(str, i)))
		i++;
	return (str[i] == c ? i : 0);
}

int			quot(t_shell *shell, char **line)
{
	char	*str;
	int		i;
	int		j;

	str = *line;
	j = 0;
	while (*str)
	{
		if (is_quot(*line, j))
		{
			if (!(i = find_next(str)))
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
		j++;
	}
	return (1);
}
