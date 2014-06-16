/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 22:35:27 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

bool		expression(t_tree **tree, t_lex **lex)
{
	return (or_exp(tree, lex));
}

bool		or_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && and_exp(tree, lex))
	{
		if (*lex)
		{
			if (!strcmp((*lex)->str, OR_BIN))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = IS_OR;
				new->left = *tree;
				*tree = new;
				*lex = (*lex)->next;
				return (or_exp(&(new->right), lex);
			}
			else
				return (FALSE);
		}
		else
			return (TRUE);
	}
	return (FALSE);
}

bool		and_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (pipe_exp(tree, lex))
	{
		if (lex)
		{
			if (!strcmp((*lex)->str, AND_BIN))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = IS_AND;
				new->left = *tree;
				*tree = new;
				return (and_exp(&(new->right), &(*lex)->next));
			}
			return (TRUE);
		}
	}
	return (FALSE);
}

bool		pipe_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (redir_exp(tree, lex))
	{
		if (*lex)
		{
			if (!strcmp((*lex)->str, PIPE))
			{
				*lex = (*lex)->next;
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = IS_PIPE;
				new->right = *tree;
				*tree = new;
				return (pipe_exp(&(new->left), &(*lex)->next));
			}
			return (TRUE);
		}
	}
	return (FALSE);
}

bool		redir_right_spe(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && is_right_redir((*lex)->str))
	{
		if (file_exp(tree, lex))
		{
			if (!alloc_tree(&new, tree))
				return (FALSE);
			new->ope = (!strcmp((*lex)->prev->prev->str, D_RIGHT_R)) 
			? IS_D_RIGHT : IS_RIGHT;
			new->right = *tree;
			*tree = new;
			*lex = (*lex)->next;
			return (command_exp(&(new->left), lex));
		}
	}
	return (FALSE);
}
