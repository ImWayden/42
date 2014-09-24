/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:51:19 by msarr             #+#    #+#             */
/*   Updated: 2014/01/03 14:51:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				*uf_get_instance(void)
{
	static t_bar		*instance = NULL;

	if (instance == NULL)
		instance = malloc(sizeof(*instance));
	return (instance);
}

static	void			mywinch(int i)
{
	t_selectlist		*list;

	i++;
	list = ((t_bar *)uf_get_instance())->list;
	ft_putstr(tgetstr("cl", NULL));
	ft_effect2(list);
	while (list->curseur != 'y')
		list = list->next;
	list = ft_setlist(list);
	ft_putstr(tgoto(tgetstr("cm", NULL), list->col, list->row));
	return ;
}

static void				delcenter(t_selectlist **list, t_selectlist **tmp)
{
	if (!ft_strcmp((*tmp)->str, (*list)->str))
	{
		*list = (*list)->next;
		*tmp = (*tmp)->next;
		(*tmp)->curseur = 'y';
		*list = ft_dellistelmt(list, (*tmp)->prev->str);
	}
	else
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->curseur = 'y';
		*list = ft_dellistelmt(list, (*tmp)->prev->str);
	}
}

static	void			choice(t_selectlist **tmp, char *buffer,
						t_selectlist **list)
{
	if (buffer[0] == 27 && tmp && *tmp)
	{
		(*tmp)->curseur = 'n';
		if (buffer[1] == 91 && buffer[2] == 'B')
			(*tmp) = (*tmp)->next;
		if (buffer[1] == 91 && buffer[2] == 'A')
			(*tmp) = (*tmp)->prev;
		(*tmp)->curseur = 'y';
	}
	else if (buffer[0] == ' ' && tmp && *tmp)
	{
		if ((*tmp)->select == 'y')
			(*tmp)->select = 'n';
		else
			(*tmp)->select = 'y';
		(*tmp) = (*tmp)->next;
	}
	else if ((buffer[0] == 8 || buffer[0] == 127) && tmp && *tmp && *list)
		delcenter(list, tmp);
}

int						ft_effect(t_selectlist **list)
{
	char				*buffer;
	t_selectlist		*tmp;

	tmp = *list;
	while (1 && *list)
	{
		((t_bar *)uf_get_instance())->list = *list;
		signal(SIGWINCH, mywinch);
		*list = ft_setlist(*list);
		ft_effect2(*list);
		ft_putstr(tgoto(tgetstr("cm", NULL), tmp->col, tmp->row));
		buffer = ft_strnew(3);
		read(0, buffer, 3);
		choice(&tmp, buffer, list);
		if (buffer[0] == 10)
			return (0);
		if (buffer[0] == 27 && buffer[1] == 1)
			return (1);
	}
	return (1);
}
