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


#include "minishell2.h"

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

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(0, &str[i++], 1);
}

char	*ft_edit(t_list **list)
{
	struct termios		term;
	char				buffer[3];
	char				*str;
	t_list				*tmp;

	if (ft_init(&term))
		return (NULL);
	if (ft_config(&term))
		return (NULL);
	str = (char *)malloc(sizeof(char));
	*str = '\0';
	tmp = *list;
	while (1)
	{
		buffer[0] = '\0';buffer[1] = '\0';buffer[2] = '\0';	
		read(0, buffer, 3);
		if (buffer[0] == 27 && tmp)
		{
			if (buffer[1] == 91 && buffer[2] == 'B' && tmp->prev)
				tmp = tmp->prev;
			if (buffer[1] == 91 && buffer[2] == 'A' && tmp->next)
				tmp = tmp->next;
			if (tmp)
			{
				ft_putstr(tgetstr("cb", NULL));
				write(1, "\r", 1);
				write(1, "$>", 2);
				ft_putstr(tmp->str);
			}
		}
		else if (buffer[0] != 27)
		{
			write(1, buffer, 1);
			if (buffer[0] == '\n')
				break ;
			str = ft_strjoin(str, buffer);
		}
	}
	ft_defconfig(&term);
	*list = ft_addlist(*list, str);
	if ((*list)->next)
	write(1, (*list)->next->str, ft_strlen((*list)->next->str));
	return (str);
}