/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defconfig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:51:54 by msarr             #+#    #+#             */
/*   Updated: 2014/01/03 14:51:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_defconfig(struct termios *term)
{
	(*term).c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	return (0);
}
