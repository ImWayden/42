/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 17:35:01 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

bool		command_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && is_word((*lex)->str))
	{
		if (!alloc_tree(&new, tree))
			return (FALSE);
		new->ope = IS_CMD;
		if (!(new->argv = ft_strsplit((*lex)->str, ' ')))
			return (FALSE);
		*lex = (*lex)->next;
		*tree = new;
		return (TRUE);
	}
	return (FALSE);
}

bool		is_word(char *str)
{
	if (str && !is_redir_or_sep(str))
		return (TRUE);
	return (FALSE);
}


bool		file_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && is_word((*lex)->str))
	{
		if (!alloc_tree(&new, tree))
			return (FALSE);
		new->ope = IS_FILE;
		if (!(new->argv = ft_strsplit((*lex)->str, ' ')))
			return (FALSE);
		*lex = (*lex)->next;
		*tree = new;
		return (TRUE);
	}
	return (FALSE);
}

bool		special_case(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (!alloc_tree(&new, tree))
		return (FALSE);
	new->ope = (!strcmp((*lex)->str, D_RIGHT_R)) ? IS_D_RIGHT : IS_RIGHT;
	new->left = *tree;
	*tree = new;
	*lex = (*lex)->next;
	return (file_exp(&(new->right), lex));
}