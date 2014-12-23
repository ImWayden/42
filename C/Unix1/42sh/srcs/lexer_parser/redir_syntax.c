/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/13 18:40:02 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "libft.h"

int			left_redir_syntax(t_lex *lex)
{
	if (lex)
	{
		if (!lex->prev || (lex->prev && (is_sep((lex->prev)->str)))
			|| is_pipe((lex->prev)->str))
		{
			if (!(lex->next) || !(lex->next->next)
				|| is_redir_or_sep((lex->next)->str)
				|| is_redir_or_sep((lex->next->next)->str))
				return (1);
		}
		if (((lex->next) && !is_redir_or_sep((lex->next)->str)))
		{
			lex = lex->prev;
			while (lex->prev && !is_semi_colon(lex->str)
				&& !is_and_or_or_bin(lex->str))
			{
				if (is_pipe(lex->str) || is_left_redir(lex->str))
					return (3);
				lex = lex->prev;
			}
			return (0);
		}
		return (2);
	}
	return (-1);
}

int			right_redir_syntax(t_lex *lex)
{
	if (lex)
	{
		if (!lex->prev || (lex->prev && (is_sep((lex->prev)->str)))
			|| is_pipe((lex->prev)->str))
			if (!lex->next || !lex->next->next
				|| is_redir_or_sep((lex->next)->str)
				|| is_redir_or_sep((lex->next->next->str)))
				return (1);
		if (lex && lex->next && !is_redir_or_sep((lex->next)->str))
		{
			lex = lex->next;
			while (lex && !is_semi_colon(lex->str)
				&& !is_and_or_or_bin(lex->str))
			{
				if (is_pipe(lex->str) || is_right_redir(lex->str))
					return (4);
				lex = lex->next;
			}
			return (0);
		}
		return (2);
	}
	return (-1);
}

int			pipe_and_or_syntax(t_lex *lex)
{
	if (is_pipe(lex->str))
	{
		if (lex->next && lex->prev && !is_redir_or_sep((lex->prev)->str)
			&& !is_sep((lex->prev)->str) && !is_sep((lex->next)->str))
			return (0);
	}
	else
	{
		if ((lex->next) && (lex->prev) && !is_pipe((lex->prev)->str)
			&& !is_pipe((lex->next)->str) && !is_sep((lex->next)->str)
			&& !is_sep((lex->prev)->str))
			return (0);
	}
	return (1);
}
