/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/02 15:57:36 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			is_operator(char c)
{
	if (c == '(' || c == ')' || c == '&' || c == '<' || c == '>' || c == '|' || c == ';')
		return (1);
	else
		return (0);
}

static int			get_operator(t_lexlist **list, char *str)
{
	if ((str[0] == '>' || str[0] == '|' || str[0] == '&') && str[0] == str[1])
	{
		*list = addlist(*list, ft_strndup(str, 2));
		return (2);
	}
	*list = addlist(*list, ft_strndup(str, 1));
	return (1);
}

t_lexlist			*lexer(char *line)
{
	t_lexlist		*list;
	int				i;

	list = NULL;
	while (line && *line)
	{
		while (*line == ' ')
			line++;
		i = 0;
		while (line[i] && !is_operator(line[i]))
			i++;
		if (i && (list = addlist(list, ft_strndup(line, i))))
			line = line + i;
		if (is_operator(*line))
			line += get_operator(&list, line);
	}
	return (list);
}

int			main()
{
	t_lexlist		*list;
	char			*str;

	str = NULL;
	list = NULL;
	while (get_next_line(1, &str))
	{
		list = lexer(str);
		while (list)
		{
			ft_putendl(list->str);
			list = list->next;
		}
	}
	return (0);
}