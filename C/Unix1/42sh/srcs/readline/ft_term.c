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

int					history(t_line **tmp, char c, char **str)
{
	int				i;

	i = 0;
	ft_memdel((void **)&(*tmp)->str);
	(*tmp)->str = *str;
	if (c == 'A' && (*tmp)->next)
	{
		i = 1;
		*tmp = (*tmp)->next;
	}
	else if (c == 'B' && (*tmp)->prev)
	{
		i = 1;
		*tmp = (*tmp)->prev;
	}
	*str = ft_strdup((*tmp)->str);
	if (i)
	{
		ft_putstr(tgetstr("rc", NULL));
		ft_putstr(tgetstr("cd", NULL));
		ft_putstr(tgetstr("sc", NULL));
		ft_putstr(*str);
		return (0);
	}
	return (1);
}

void				ft_read(char *buf)
{
	ft_bzero(buf, 5);
	read(0, buf, 5);
}

char				*ft_term(t_shell *shell, int j, int f)
{
	char			buf[5];
	t_line			*tmp;
	char			*str;

	tmp = shell->hist;
	str = NULL;
	ft_putstr(tgetstr("sc", NULL));
	f = 0;
	while (42)
	{
		ft_read(buf);
		if (buf[0] == '\n')
			return (exit_mode(shell, str, j));
		else if (K_UP(buf))
			f *= history(&tmp, 'A', &str);
		else if (K_DOWN(buf))
			f *= history(&tmp, 'B', &str);
		else if (K_END(buf))
			f = 0;
		else if (K_HOME(buf))
			f = ft_strlen(str);
		else
			term_center(shell, &str, buf, &f);
	}
	return (str);
}
