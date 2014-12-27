/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 11:01:38 by msarr             #+#    #+#             */
/*   Updated: 2014/12/27 11:01:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "42sh.h"

int			is_quot(char c)
{
	if (c == '\'' || c == '\"' || c == '`')
		return (1);
	return (0);
}

int			quot(t_shell *shell, char **line, int *i, int f)
{
	char	*str;

	str = NULL;
	ft_putendl("quot");
	while (*line && (*line)[*i] && (*line)[*i] != f)
	{
		ft_putchar(*line[*i]);
		ft_putchar('\n');
		if(is_quot((*line)[*i]) && ((*i - 1) < 0 || *line[*i - 1] != '\\') )
		{
			(*i)++;
			*i = quot(shell, line, i, *line[*i - 1]);
		}
		else
			*i += 1;
	}
	if (!(*line)[*i] || (*line)[*i] != f)
	{
		str = get_line(shell, 0, 1);
		*line = ft_strjoin(*line, str);
		ft_memdel((void **)&str);
		return (quot(shell, line, i, f));
	}
	else
		return (*i);
	return (1);
}