/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 09:03:05 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

t_bool		redir_exp(t_tree **tree, t_lex **lex)
{
	t_lex		*bkup;

	bkup = *lex;
	if (!redir_left_norm(tree, lex))
	{
		*lex = bkup;
		if (!redir_left_spe(tree, lex))
			return (FALSE);
	}
	return (TRUE);
}

t_bool		redir_left_norm(t_tree **tree, t_lex **lex)
{
	t_bool	ret;
	t_tree	*new;

	if (redir_right(tree, t))
	{
		if (*lex)
		{
			if (is_left_redir((*lex)->str))
			{
				if (!alloc_tree(&new, tree))
					return (FALSE);
				new->ope = (!strcmp((*lex)->str, D_LEFT_R))
				? IS_D_LEFT : IS_LEFT;
				new->left = *tree;
				*tree = new;
				lex = (*lex)->next;
				ret = file_exp(&(new->right), lex);
				while (args_exp(tree, t) && t->i++);
				return ((is_right_redir(t->board[t->i]))
					? special_case(tree, t) : ret);
			}
		}
		return (TRUE);
	}
	return (FALSE);
}

t_bool		redir_left_spe(t_tree **tree, t_lex **lex)
{
	t_bool	ret;
	t_tree	*new;

	if (is_left_redir(t->board[t->i++]))
	{
		if (file_exp(tree, t))
		{
			if (!alloc_tree(&new, *tree))
				return (FALSE);
			new->type = (!strcmp(t->board[t->i - 2], D_LEFT_R))
			? IS_D_LEFT : IS_LEFT;
			new->right = *tree;
			*tree = new;
			ret = command_exp(&(new->left), t);
			return ((is_right_redir(t->board[t->i]))
				? special_case(tree, t) : ret);
		}
	}
	return (FALSE);
}

t_bool		redir_right(t_tree **tree, t_lex **lex)
{
	int		bkup;

	bkup = t->i;
	if (!redir_right_norm(tree, t))
	{
		t->i = bkup;
		if (!redir_right_spe(tree, t))
			return (FALSE);
	}
	return (TRUE);
}

t_bool		redir_right_norm(t_tree **tree, t_lex **lex)
{
	t_bool	ret;
	t_tree	*new;

	if (command_exp(tree, t))
	{
		if (t->board[t->i] && is_right_redir(t->board[t->i]))
		{
			if (!alloc_tree(&new, *tree))
				return (FALSE);
			new->type = (!strcmp(t->board[t->i], D_RIGHT_R))
			? IS_D_RIGHT : IS_RIGHT;
			new->left = *tree;
			*tree = new;
			t->i++;
			ret = file_exp(&(new->right), t);
			while (args_exp(tree, t) && t->i++);
			return (ret);
		}
		return (TRUE);
	}
	return (FALSE);
}

