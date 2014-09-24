/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 21:25:24 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

bool		command_exp(t_tree **tree, t_lex **lex)
{
	t_tree	*new;

	if (*lex && is_word((*lex)->str))
	{
		ft_putendl("cmd");
		if (!alloc_tree(&new, tree))
			return (FALSE);
		new->ope = IS_CMD;
		if (!(new->argv = ft_strsplit((*lex)->str, ' ')))
			return (FALSE);
		*tree = new;
		*lex = (*lex)->next;
		if (*lex)
			ft_putendl((*lex)->str);
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
		ft_putendl("file");
		if (!alloc_tree(&new, tree))
			return (FALSE);
		new->ope = IS_FILE;
		if (!(new->argv = ft_strsplit((*lex)->str, ' ')))
			return (FALSE);
		*tree = new;
		*lex = (*lex)->next;
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
