/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:11:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/22 21:06:11 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		init(struct termios *term)
{
	char	*termname;

	if ((termname = getenv("TERM")) == NULL)
		return (0);
	if (tgetent(NULL, termname) == ERR)
		return (0);
	if (tcgetattr(0, term) == -1)
		return (0);
	return (1);
}

int		config(struct termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (0);
	return (1);
}

int		defconfig(struct termios *term)
{
	(*term).c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (0);
	return (1);
}

