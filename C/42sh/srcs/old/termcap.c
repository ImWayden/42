/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:11:12 by msarr             #+#    #+#             */
/*   Updated: 2014/02/04 13:11:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int		ft_init(struct termios *term)
{
	char	*termname;

	if ((termname = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, termname) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	return (0);
}

int		ft_config(struct termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (0);
}

int		ft_defconfig(struct termios *term)
{
	(*term).c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	return (0);
}

char		*ft_put(int i, char *str, char **envs)
{
	char				*buffer;
	int					ret;
	int					j;

	buffer = ft_strnew(3);
	ft_putstr(tgetstr("dl", NULL));
	write(1, "\r", 1);
	ft_prompt(envs);
	ft_putstr(str);
	j = i;
	if (j > 0)
		while(j--)
			ft_putstr(tgetstr("nd", NULL));
	else if (j < 0)
		while(j++)
			ft_putstr(tgetstr("le", NULL));
	ret = read(0, buffer, 3);
	buffer[ret] = '\0';
	return (buffer);
}

t_termlist			*ft_choice(char *buffer, t_termlist *list, char **str, int *i)
{
	if (buffer[0] == 27 && buffer[1] == 91 && list)
	{
		if (*str)
			list->str = *str;
		if (buffer[2] == 'B' && list->prev)
			list = list->prev;
		else if (buffer[2] == 'A' && list->next)
			list = list->next;
		else 
		{
			if (buffer[2] == 'C' && *i)
				(*i)++;
			if (buffer[2] == 'D' && ((*i) * -1) < (int)ft_strlen(*str))
				(*i)--;
		}
		if (buffer[2] == 'B' || buffer[2] == 'A')
			(*i) = 0;
		*str = ft_strdup(list->str);
		return (list);
	}
	else if (buffer[0] == '\n')
		return (NULL);
	else if (buffer[0] == 127)
		*str = ft_del(*str, *i);
	else if (ft_isprint(buffer[0]) && !buffer[1])
		*str = ft_join(*str, buffer, *i);
	return (list);
}