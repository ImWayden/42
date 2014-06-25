/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 21:16:43 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

bool		expression(t_tree **tree, t_lex **lex)
{
	if (*lex)		
		return (or_exp(tree, lex));
	else
		return (FALSE);
}

bool		or_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && and_exp(tree, lex))
	{
		if (lex && *lex)
		{
			if (!strcmp((*lex)->str, OR_BIN))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = IS_OR;
				new->left = *tree;
				*tree = new;
				*lex = (*lex)->next;
				return (or_exp(&(new->right), lex));
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

	if (*lex && pipe_exp(tree, lex))
	{
		if (lex && *lex)
		{
			if (!strcmp((*lex)->str, AND_BIN))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = IS_AND;
				new->left = *tree;
				*tree = new;
				*lex = (*lex)->next;
				return (and_exp(&(new->right), lex));
			}
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

bool		pipe_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && redir_exp(tree, lex))
	{
		if (lex && *lex)
		{
			if (!strcmp((*lex)->str, PIPE))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = IS_PIPE;
				new->right = *tree;
				*tree = new;
				*lex = (*lex)->next;
				return (pipe_exp(&(new->left), lex));
			}
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

bool		redir_exp(t_tree **tree, t_lex **lex)
{
	t_lex		*bkup;

	bkup = *lex;
	if (!redir_left_norm(tree, lex))
	{
		*lex = bkup;
		return(redir_left_spe(tree, lex));
	}
	return (TRUE);
}
