/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 01:33:45 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "shell.h"

static int			get_operator(t_lex **list, char *str)
{
	if (ft_strchr(OPE, str[0]) && str[0] == str[1])
	{
		*list = addlist(*list, ft_strndup(str, 2));
		return (2);
	}
	*list = addlist(*list, ft_strndup(str, 1));
	return (1);
}

static t_lex		*ft_listnew(char *str)
{
	t_lex			*list;

	if ((list = (t_lex *)malloc(sizeof(t_lex))))
	{
		list->str = str;
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}

t_lex				*addlist(t_lex *list, char *str)
{
	t_lex			*tmp;
	t_lex			*tmp1;

	tmp = ft_listnew(str);
	if (!list)
		list = tmp;
	else
	{
		tmp1 = list;
		while (tmp1->next)
			tmp1 = tmp1->next;
		tmp->prev = tmp1;
		tmp1->next = tmp;
	}
	return (list);
}

t_lex				*lexer(char *line)
{
	t_lex			*list;
	int				i;

	list = NULL;
	while (line && *line)
	{
		while (ft_strchr(SEP, *line))
			line++;
		i = 0;
		while (line[i] && !ft_strchr(OPE, line[i]))
		{
			if (line[i] == '\t')
				line[i] = ' ';
			i++;
		}
		if (i && (list = addlist(list, ft_strndup(line, i))))
			line = line + i;
		if (*line && ft_strchr(OPE, *line))
			line += get_operator(&list, line);
	}
	return (list);
}
