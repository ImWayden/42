/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/15 21:55:25 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

bool		expression(t_tree **tree, lex_lex **lex)
{
	return (or_exp(tree, lex));
}

bool		or_exp(t_tree **tree, lex_lex **lex)
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
				return (or_exp(&(new->right), &(*lex)->next));
			}
			else
				return (FALSE);
		}
		else
			return (TRUE);
	}
	return (FALSE);
}

bool		and_exp(t_tree **tree, lex_lex **lex)
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

bool		pipe_exp(t_tree **tree, lex_lex **lex)
{
	t_tree	*new;

	if (redir_exp(tree, lex))
	{
		if (*lex)
		{
			if (!strcmp((*lex)->str, PIPE))
			{
				*lex = (*lex)->next
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->type = IS_PIPE;
				new->right = *tree;
				*tree = new;
				return (pipe_exp(&(new->left), &(lex->next)));
			}
			return (TRUE);
		}
	}
	return (FALSE);
}

bool		redir_right_spe(t_tree **tree, lex_lex **lex)
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
			return (command_exp(&(new->left), &(lex->next)));
		}
	}
	return (FALSE);
}
