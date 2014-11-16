/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 22:02:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

int					exit_mode(char **str, char **str1)
{
	ft_putendl(NULL);
	*str = *str1;
	return (1);
}

int					editing(char *str, int j, int len)
{
	if (str[0] == 27)
	{
		if (str[1] == 91 && str[2] == 'C' && j > 0)
			return (-1);
		if (str[1] == 91 && str[2] == 'D' && j < len)
			return (1);
	}
	return (0);
}

void				term_center(t_shell *shell, char **str, char *buf, int *j)
{
	if (buf[0] == '\t')
		autoimpl(str, shell, *j);
	else if (ft_isprint(buf[0]) && buf[0] != '^' && *j > 0)
		insert_mode(str, *j, buf[0]);
	else if (buf[0] == 127)
		delete_mode(str, *j + 1);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == '3')
		*j += delete_mode(str, *j - 1);
	else if (ft_isprint(buf[0]) && buf[0] != '^')
		ft_join(str, buf);
	else if (buf[0] != '\n')
		*j += editing(&(buf[0]), *j, ft_strlen(*str));
}

int					history(t_line **tmp, char c, char **str)
{
	if (c == 'A' && !(*tmp)->prev)
		(*tmp)->str = *str;
	if (c == 'A' && (*tmp)->next)
	{
		*tmp = (*tmp)->next;
		ft_memdel((void **)str);
		*str = ft_strdup((*tmp)->str);
		return (0);
	}
	else if (c == 'B' && (*tmp)->prev)
	{
		*tmp = (*tmp)->prev;
		ft_memdel((void **)str);
		*str = ft_strdup((*tmp)->str);
		return (0);
	}
	return (1);
}

int					ft_term(char **str, t_shell *shell, int j)
{
	char			buf[4];
	t_line			*tmp;
	char			*str1;

	tmp = shell->hist;
	str1 = NULL;
	while (print_promt(shell, str1, j))
	{
		ft_bzero(buf, 4);
		read(0, buf, 4);
		if (buf[0] == '\n')
			return (exit_mode(str, &str1));
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'A' && tmp->next)
			j *= history(&tmp, 'A', &str1);
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'B' && tmp->prev)
			j *= history(&tmp, 'B', &str1);
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'F')
			j = 0;
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'H')
			j = ft_strlen(str1);
		else
			term_center(shell, &str1, buf, &j);
	}
	return (1);
}
