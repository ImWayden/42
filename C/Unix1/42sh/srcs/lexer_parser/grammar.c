/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/13 12:29:24 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

bool		is_left_redir(char *str)
{
	if (str && (!ft_strcmp(str, LEFT_R) || !ft_strcmp(str, D_LEFT_R)))
		return (TRUE);
	return (FALSE);
}

bool		is_right_redir(char *str)
{
	if (str && (!ft_strcmp(str, RIGHT_R) || !ft_strcmp(str, D_RIGHT_R)))
		return (TRUE);
	return (FALSE);
}

bool		is_pipe(char *str)
{
	if (str && !ft_strcmp(str, PIPE))
		return (TRUE);
	return (FALSE);
}

bool		is_and_or_or_bin(char *str)
{
	if (str && (!ft_strcmp(str, AND_BIN) || !ft_strcmp(str, OR_BIN)))
		return (TRUE);
	return (FALSE);
}

bool		is_semi_colon(char *str)
{
	if (str && !ft_strcmp(str, SEMICOLON))
		return (TRUE);
	return (FALSE);
}
