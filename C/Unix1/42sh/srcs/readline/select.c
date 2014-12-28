/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:23:13 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 22:50:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void				replace_word(t_line *list, char **str, int len)
{
	int				i;
	int				j;
	char			*str1;

	i = ft_strlen(*str) - 1 - len;
	j = 0;
	if (i >= 0)
		str1 = ft_strdup(&(*str)[i + 1]);
	while (i >= 0 && ft_isalnum((*str)[i]))
	{
		i--;
		j++;
	}
	if (j)
		(*str)[++i] = '\0';
	ft_join(str, list->str);
	if (!str1 || !*str1)
		ft_join(str, " ");
	else
		ft_join(str, str1);
}

void				put_word(t_line *list, int i)
{
	int				k;
	int				j;
	struct winsize	mywin;

	ft_putendl(NULL);
	j = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
	while (list)
	{
		k = ft_strlen(list->str);
		ft_putstr(list->str);
		while (k < i && list->next)
		{
			ft_putchar(' ');
			k++;
		}
		j += k;
		if ((j + i > mywin.ws_col && !(j = 0)) || !list->next)
			ft_putendl(NULL);
		list = list->next;
		k = 0;
	}
}

int					big_word(t_line *list)
{
	int				i;

	i = 0;
	while (list)
	{
		if (i < ft_strlen(list->str))
			i = ft_strlen(list->str);
		list = list->next;
	}
	return (i);
}

void				setlist(t_line **list, char **str, int len)
{
	t_line			*tmp;
	int				i;

	tmp = *list;
	i = big_word(tmp) + 2;
	if (tmp && !tmp->next)
	{
		replace_word(tmp, str, len);
		ft_putchar('\r');
	}
	else if (tmp)
	{
		put_word(tmp, i);
	}
}
