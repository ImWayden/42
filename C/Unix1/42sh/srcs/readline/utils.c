/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:12:00 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 03:04:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "shell.h"

int			ft_init(t_termios *term)
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

int			ft_config(t_termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (0);
}

int			ft_defconfig(t_termios *term)
{
	(*term).c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (0);
}

int			print(char *str, int j, char *buf)
{
	if (((K_LEFT(buf) || K_DEL(buf)) && j <= ft_strlen(str))
		|| (K_RIGHT(buf) && j >= 0) || (ft_isprint(*buf) && !j))
		ft_putstr(buf);
	else if (K_HOME(buf))
		ft_putstr(tgetstr("rc", NULL));
	else if (K_END(buf))
		ft_putstr(tgetstr("cd", NULL));
	return (1);
}

void		term_center(t_shell *shell, char **str, char *buf, int *j)
{
	int		i;

	i = 0;
	if (K_DEL(buf))
		delete_mode(str, *j + 1, buf);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == '3')
		i += delete_mode(str, *j - 1, buf);
	else if (K_LEFT(buf) || K_RIGHT(buf) || ft_isprint(buf[0]))
	{
		if (ft_isprint(*buf))
			ft_join(str, buf);
		else
			i = editing(&(buf[0]), *j, ft_strlen(*str));
		if (ft_isprint(*buf) || i)
			ft_putstr(buf);
	}
	else if (ft_isprint(buf[0]) && *j > 0)
		insert_mode(str, *j, buf[0], buf);
	*j += i;
	(void)shell;
}
