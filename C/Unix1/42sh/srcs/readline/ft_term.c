/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:54 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 03:02:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "grammar.h"

char				*exit_mode(t_shell *shell, char *str, int j)
{
	ft_putendl(NULL);
	if (!j)
	{
		ft_memdel((void **)&shell->hist->str);
		shell->hist->str = ft_strdup(str);
	}
	else
	{
		if (j == 2)
			ft_join(&shell->hist->str, "\n");
		ft_join(&shell->hist->str, ft_strdup(str));
	}
	return (str);
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
	if (ft_isprint(buf[0]) && *j > 0)
		insert_mode(str, *j, buf[0]);
	else if (buf[0] == 127)
		delete_mode(str, *j + 1);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == '3')
		*j += delete_mode(str, *j - 1);
	else if (ft_isprint(buf[0]))
		ft_join(str, buf);
	else if (buf[0] != '\n')
		*j += editing(&(buf[0]), *j, ft_strlen(*str));
	(void)shell;
}


int					history(t_line **tmp, char c, char **str)
{
	ft_memdel((void **)&(*tmp)->str);
	(*tmp)->str = *str;
	if (c == 'A' && (*tmp)->next)
		*tmp = (*tmp)->next;
	else if (c == 'B' && (*tmp)->prev)
		*tmp = (*tmp)->prev;
	*str = ft_strdup((*tmp)->str);
	return (0);
}


char				*ft_term(t_shell *shell, int j)
{
	char			buf[5];
	int				f;
	t_line			*tmp;
	char			*str;

	tmp = shell->hist;
	str = NULL;
	ft_putstr(tgetstr("sc", NULL));
	f = 0;
	while (42)
	{
		print(str, f, buf);
		ft_bzero(buf, 5);
		read(0, buf, 4);
		ft_putnbr(buf[0]);
		ft_putchar(buf[0]);
		if (buf[0] == '\n')
			return (exit_mode(shell, str, j));
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'A')
			f *= history(&tmp, 'A', &str);
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'B')
			f *= history(&tmp, 'B', &str);
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'F')
			f = 0;
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'H')
			f = ft_strlen(str);
		else
			term_center(shell, &str, buf, &f);
	}
	return (str);
}
