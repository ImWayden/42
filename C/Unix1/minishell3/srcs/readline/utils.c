/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:12:00 by msarr             #+#    #+#             */
/*   Updated: 2014/11/12 21:01:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

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

void		ft_termcaps(void)
{
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(tgetstr("dl", NULL));
}
