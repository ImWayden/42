/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 00:22:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "42sh.h"

bool		is_left_redir(char *str)
{
	if (str && (!ft_strcmp(str, R_LEFT) || !ft_strcmp(str, DR_LEFT)))
		return (TRUE);
	return (FALSE);
}

bool		is_right_redir(char *str)
{
	if (str && (!ft_strcmp(str, R_RIGHT) || !ft_strcmp(str, DR_RIGHT)))
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
