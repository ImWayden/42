/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/15 15:15:52 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

bool		command_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && cmd_exp(tree, *lex))
	{
		if (!alloc_tree(&new, tree))
			return (FALSE);
		new->type = IS_CMD;
		if (!(new->argv = ft_strsplit((*lex)->str)))
			return (FALSE);
		*list = (*list)->next;
		*tree = new;
		return (TRUE);
	}
	return (FALSE);
}

bool		cmd_exp(t_tree **tree, t_lex **lex)
{
	(void)tree;
	if (*lex && !is_redir_or_sep((*lex)->str))
		return (TRUE);
	return (FALSE);
}

bool		args_exp(t_tree **tree, t_lex **lex)
{
	return (cmd_exp(tree, lex));
}

bool		file_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && !is_redir_or_sep((*lex)->str))
	{
		if (!alloc_tree(&new, tree))
			return (FALSE);
		new->ope = IS_FILE;
		if (!(new->args = ft_strsplit((*lex)->str)))
			return (FALSE);
		*tree = new;
		return (TRUE);
	}
	return (FALSE);
}
