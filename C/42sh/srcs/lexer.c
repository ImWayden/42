/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/05/27 08:30:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_lexlist		*addlist(t_lexlist *list, char *str)
{
	t_lexlist	*tmp;
	t_lexlist 	*tmp1;

	tmp = (t_lexlist *)malloc(sizeof(t_lexlist));
	tmp->str = str;
	tmp->next = NULL;
	if (!list)
		return (tmp);
	else
	{
		tmp1 = list;
		while (tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
	}
	return (list);
}
static int			lexemlen(char *lex)
{
	int				i;

	i = 0;
	while (lex && lex[i] && lex[i] != ' ')
		i++;
	return (i);
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
		if ((i = lexemlen(line)))
		{
			list = addlist(list, ft_strndup(line, i));
			line =  &line[i];
		}
		else
			break ;
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