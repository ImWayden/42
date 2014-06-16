/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 01:24:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int				ft_is(char *str, int c)
{
	int					i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


static int			is_comment(char *str)
{
	if (str && str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

static t_getline	*addlist(t_getline *list, char *str)
{
	t_getline	*tmp;
	t_getline	*tmp1;

	if ((tmp = (t_getline *)malloc(sizeof(t_getline))))
	{
		tmp->next = NULL;
		tmp->str = ft_strdup(str);
		tmp1 = list;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		if (tmp1)
			tmp1->next = tmp;
		else
			list = tmp;
	}
	return (list);
}

static t_getline	*lexor()
{
	char			*str;
	t_getline		*list;

	str = NULL;
	list = NULL;
	while (get_next_line(0, &str))
	{
		ft_putendl(str);
		if (is_comment(str))
			break ;
		else if (str && (*str == 'L' || *str == '\0'))
			return (list);
		else if (str)
			list = addlist(list, str);
	}
	return (list);
}

t_lem				*parse()
{
	t_lem			*pars;
	t_getline		*list;

	list = NULL;
	if ((list == lexor()) && (pars = newlem()))
	{
		if (!(pars->j = ft_atoi(list->str)))
			return (pars);
		while ((list = list->next))
		{
			if (!ft_strcmp(list->str, "##start"))
				pars->start = ft_strdup(list->next->str);
			if (!ft_strcmp(list->str, "##end"))
				pars->end = ft_strdup(list->next->str);
			else if (ft_is(list->str, ' '))
				get_room(list->str, pars);
			else if (ft_is(list->str, '-'))
				get_tab(list->str, pars);
			list = list->next;
		}
		return (pars);
	}
	return (NULL);
}
