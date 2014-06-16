/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/11 14:12:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			is_ope(char c)
{
	if (c == '(' || c == ')' || c == '&' || c == '<' || c == '>' || c == '|'
		|| c == ';')
		return (TRUE);
	else
		return (FALSE);
}

bool				is_ope_and(char *token)
{
	if (!ft_strcmp(token, "&&"))
		return (TRUE);
	else
		return (FALSE);
}

bool				is_ope_or(char *token)
{
	if (!ft_strcmp(token, "||"))
		return (TRUE);
	else
		return (FALSE);
}

bool				is_ope_pipe(char *token)
{
	if (!ft_strcmp(token, "|"))
		return (TRUE);
	else
		return (FALSE);
}

bool				is_ope_left(char *token)
{
	if (!ft_strcmp(token, "<") || !ft_strcmp(token, "<<"))
		return (TRUE);
	else
		return (FALSE);
}

bool				is_ope_right(char *token)
{
	if (!ft_strcmp(token, ">") || !ft_strcmp(token, ">>"))
		return (TRUE);
	else
		return (FALSE);
}


bool				is_ope_semi(char *token)
{
	if (!ft_strcmp(token, "&&"))
		return (TRUE);
	else
		return (FALSE);
}

bool				is_word(char *token)
{
	if (!ft_strcmp(token, "&&"))
		return (TRUE);
	else
		return (FALSE);
}
