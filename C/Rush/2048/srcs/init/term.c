/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:55:52 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 20:55:52 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			term(void)
{
	char	*termname;

	if (!(termname = getenv("TERM")))
		return (0);
	if (tgetent(NULL, termname) == ERR)
		return (0);
	return (1);
}