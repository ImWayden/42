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
#include "my_42sh.h"

bool		redir_left_norm(t_tree **tree, t_lex **lex)
{
	bool	ret;
	t_tree	*new;

	if (redir_right(tree, lex))
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
				*lex = (*lex)->next;
				ret = file_exp(&(new->right), lex);
				return ((is_right_redir((*lex)->str))
					? special_case(tree, lex) : ret);
			}
			return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

bool		redir_left_spe(t_tree **tree, t_lex **lex)
{
	bool	ret;
	t_tree	*new;

	if (is_left_redir((*lex)->str))
	{
		if (*lex)
			*lex = (*lex)->next;
		if (file_exp(tree, lex))
		{
			if (!alloc_tree(&new, tree))
				return (FALSE);
			new->ope = (!strcmp((*lex)->prev->prev->str, D_LEFT_R))
			? IS_D_LEFT : IS_LEFT;
			new->right = *tree;
			*tree = new;
			ret = command_exp(&(new->left), lex);
			return ((is_right_redir((*lex)->str)
				? special_case(tree, lex) : ret));
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

	if (command_exp(tree, lex))
	{
		if (*lex && is_right_redir((*lex)->str))
		{
			ft_putendl("HERE");
			if (!alloc_tree(&new, tree))
				return (FALSE);
			new->ope = (!strcmp((*lex)->str, D_RIGHT_R)) ? IS_D_RIGHT : IS_RIGHT;
			ft_putnbr(new->ope);
			new->left = *tree;
			*tree = new;
			*lex = (*lex)->next;
			return (file_exp(&(new->right), lex));
		}
		if (!(*lex))
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
			new->ope = (!strcmp((*lex)->prev->prev->str, D_RIGHT_R)) 
			? IS_D_RIGHT : IS_RIGHT;
			new->right = *tree;
			*tree = new;
			return (command_exp(&(new->left), lex));
		}
	}
	return (FALSE);
}
