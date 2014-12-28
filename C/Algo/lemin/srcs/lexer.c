/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 17:25:20 by msarr             #+#    #+#             */
/*   Updated: 2014/12/07 22:51:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_comment(char *str)
{
	if (str && str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

static t_lex	*listnew(char *str)
{
	t_lex		*list;

	if ((list = (t_lex *)malloc(sizeof(t_lex))))
	{
		list->str = ft_strtrim(str);
		list->next = list;
		list->prev = list;
	}
	return (list);
}

static t_lex	*addlist(t_lex *list, char *str)
{
	t_lex		*tmp;

	tmp = listnew(str);
	if (!list)
		return (tmp);
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	return (list);
}

t_lex			*get_lst(void)
{
	t_lex		*lst;
	char		*str;

	lst = NULL;
	str = NULL;
	while ((get_next_line(0, &str)))
	{
		if (*str == 'L')
			break ;
		else if (is_comment(str))
			continue ;
		else
		{
			ft_putendl(str);
			lst = addlist(lst, str);
		}
		ft_memdel((void **)&str);
	}
	return (lst);
}
