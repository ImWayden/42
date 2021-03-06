/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 00:22:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "shell.h"

bool		redir_left_norm(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	new = NULL;
	if (*lex && redir_right(tree, lex))
	{
		if (*lex)
		{
			if (is_left_redir((*lex)->str))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = (!strcmp((*lex)->str, DR_LEFT))
				? IS_D_LEFT : IS_LEFT;
				new->left = *tree;
				*tree = new;
				*lex = (*lex)->next;
				return (file_exp(&(new->right), lex));
			}
		}
		return (TRUE);
	}
	return (FALSE);
}

bool		redir_left_spe(t_tree **tree, t_lex **lex)
{
	bool	ret;
	t_tree	*new;

	if (*lex && is_left_redir((*lex)->str))
	{
		if (*lex)
			*lex = (*lex)->next;
		if (file_exp(tree, lex))
		{
			if (!alloc_tree(&new, tree))
				return (FALSE);
			new->ope = (!strcmp((*lex)->prev->prev->str, DR_LEFT))
			? IS_D_LEFT : IS_LEFT;
			new->right = *tree;
			*tree = new;
			ret = command_exp(&(new->left), lex);
			ret = is_right_redir((*lex)->str) ? special_case(tree, lex) : ret;
			return (ret);
		}
	}
	return (FALSE);
}

bool		redir_right(t_tree **tree, t_lex **lex)
{
	t_lex	*bkup;

	bkup = *lex;
	if (!redir_right_norm(tree, lex))
	{
		*lex = bkup;
		return (redir_right_spe(tree, lex));
	}
	return (TRUE);
}

bool		redir_right_norm(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && command_exp(tree, lex))
	{
		if (*lex && is_right_redir((*lex)->str))
		{
			if (!alloc_tree(&new, tree))
				return (FALSE);
			new->ope = (!strcmp((*lex)->str, DR_RIGHT)) ?
			IS_D_RIGHT : IS_RIGHT;
			new->left = *tree;
			*tree = new;
			*lex = (*lex)->next;
			return (file_exp(&(new->right), lex));
		}
		return (TRUE);
	}
	return (FALSE);
}

bool		redir_right_spe(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && is_right_redir((*lex)->str))
	{
		*lex = (*lex)->next;
		if (file_exp(tree, lex))
		{
			if (!alloc_tree(&new, tree))
				return (FALSE);
			new->ope = (!strcmp((*lex)->prev->prev->str, DR_RIGHT))
			? IS_D_RIGHT : IS_RIGHT;
			new->right = *tree;
			*tree = new;
			return (command_exp(&(new->left), lex));
		}
	}
	return (FALSE);
}
