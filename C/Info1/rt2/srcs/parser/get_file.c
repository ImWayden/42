/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 17:25:20 by msarr             #+#    #+#             */
/*   Updated: 2014/11/30 22:49:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

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

t_lex			*get_file(char *file)
{
	int			fd;
	t_lex		*lst;
	char		*str;

	lst = NULL;
	str = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((get_next_line(fd, &str)))
	{
		lst = addlist(lst, str);
		ft_memdel((void **)&str);
	}
	return (lst);
}
