/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:51:19 by msarr             #+#    #+#             */
/*   Updated: 2014/10/14 00:22:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			*uf_get_instance(void)
{
	static t_bar	*instance = NULL;

	if (instance == NULL)
		instance = malloc(sizeof(*instance));
	return (instance);
}

static	void		mywinch(int i)
{
	t_select		*list;
	int				argc;

	i++;
	list = ((t_bar *)uf_get_instance())->list;
	argc = ((t_bar *)uf_get_instance())->argc;
	list = ft_setlist(list, argc);
	ft_effect2(list);
	ft_putstr(tgoto(tgetstr("cm", NULL), list->col, list->row));
	return ;
}

static void 			moove(t_select *list)
{
	if (list && list->pos < list->next->pos)
	{
		moove(list->next);
		list->next->pos = list->pos;
		list->next->col = list->col;
		list->next->row = list->row;
	}
}

static int			delcenter(t_select **list, int argc)
{
	moove(*list);
	*list = (*list)->next;
	(*list)->curseur = 'y';
	ft_dellistelmt(&(*list)->prev);
	return (--argc);
}

static	int		choice(t_select **tmp, char *buf, int argc)
{
	if (buf[0] == 27 && tmp && *tmp)
	{
		(*tmp)->curseur = 'n';
		if (buf[1] == 91 && buf[2] == 'B')
			*tmp = (*tmp)->next;
		if (buf[1] == 91 && buf[2] == 'A')
			*tmp = (*tmp)->prev;
		(*tmp)->curseur = 'y';
	}
	else if (buf[0] == ' ' && tmp && *tmp)
	{
		if ((*tmp)->select == 'y')
			(*tmp)->select = 'n';
		else
			(*tmp)->select = 'y';
		*tmp = (*tmp)->next;
	}
	else if (buf[0] == 8 || buf[0] == 127)
		return (delcenter(tmp, argc));
	return (argc);
}

int						ft_effect(t_select **list, int argc)
{
	char				*buf;

	if ((*list = ft_setlist(*list, argc)))
		(*list)->curseur = 'y';
	while (*list && argc)
	{
		((t_bar *)uf_get_instance())->list = *list;
		((t_bar *)uf_get_instance())->argc = argc;
		//signal(SIGWINCH, mywinch);
		ft_effect2(*list);
		ft_putstr(tgoto(tgetstr("cm", NULL), (*list)->col, (*list)->row));
		buf = ft_strnew(3);
		signal(SIGWINCH, mywinch);
		read(0, buf, 3);
		argc = choice(list, buf, argc);
		if (buf[0] == 10)
			return (0);
		if (buf[0] == 27 && buf[1] == 1)
			return (1);
	}
	return (1);
}
