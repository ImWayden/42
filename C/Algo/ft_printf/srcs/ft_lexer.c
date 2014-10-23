/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:42:27 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:42:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_lex		*ft_listnew(char *str)
{
	t_lex			*list;

	if ((list = (t_lex *)malloc(sizeof(t_lex))))
	{
		list->name = str;
		list->next = list;
		list->prev = list;
	}
	return (list);
}

static t_lex		*addlist(t_lex *list, char *str)
{
	t_lex			*tmp;

	tmp = ft_listnew(str);
	if (!list)
		list = tmp;
	else
	{
		tmp->prev = list->prev;
		tmp->next = list;
		list->prev->next = tmp;
		list->prev = tmp;
	}
	return (list);
}

static int		get_args(t_lex **list, char *line, int i)
{
	int				j;

	j = i;
	i++;
	while (line[i] && !ft_isalpha(line[i]))
		i++;
	if (line[i] == 's'|| line[i] == 'i' || line[i] == 'd'
		|| line[i] == 'c' || line[i] == 'x' || line[i] == 'o'
		|| line[i] == 'p')
	{
		*list = addlist(*list, ft_strsub(line, j, i - j + 1));
		return (i - j + 1);
	}
	return (0);
}

t_lex				*lexer(char *line)
{
	int		i;
	t_lex	*list;

	list = NULL;
	while (line[0])
	{ 
		i = 0;
		while (line[i] && line[i] != '%')
			i++;
		if (i)
			list = addlist(list, ft_strsub(line, 0, i));
		if (line[i] && line[i] == '%' && line[i + 1] == '%')
		{
			list = addlist(list, ft_strdup("%"));
			i += 2;
		}
		if (line[i] && line[i] == '%' && line[i + 1] != '%')
			i += get_args(&list, line, i);
		line += i;
	}
	return (list);
}
