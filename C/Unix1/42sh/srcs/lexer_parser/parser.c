/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 01:37:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "42sh.h"

t_tree				*init_tree(void)
{
	t_tree			*tree;

	if ((tree = (t_tree *)malloc(sizeof(t_tree))))
	{
		tree->right = NULL;
		tree->left = NULL;
		tree->next = NULL;
		tree->argv = NULL;
		tree->fd[0] = 0;
		tree->fd[1] = 1;
	}
	return (tree);
}

t_lex				*separate_lex(t_lex **lex)
{
	t_lex			*tmp;
	t_lex			*tmp1;

	tmp = *lex;
	tmp1 = *lex;
	while (tmp && !is_semi_colon(tmp->str))
		tmp = tmp->next;
	if (tmp && is_semi_colon(tmp->str))
	{
		*lex = tmp->next;
		if (tmp->prev)
			tmp->prev->next = NULL;
		if (*lex)
			(*lex)->prev = NULL;
		ft_memdel((void **)&(tmp->str));
		ft_memdel((void **)&tmp);
	}
	else
		*lex = NULL;
	return (tmp1);
}

static t_tree		*reset(t_tree **tree, t_lex **lexem, t_lex **lex)
{
	if (*tree)
		free_tree(tree);
	free_lex(lexem);
	free_lex(lex);
	return (NULL);
}

t_tree				*make_parsing(t_lex **lexem)
{
	t_lex			*lex;
	t_lex			*lex1;
	t_tree			*res;
	t_tree			*tmp;

	res = NULL;
	lex = separate_lex(lexem);
	lex1 = lex;
	if (!expression(&res, &lex))
		return (reset(&res, lexem, &lex1));
	free_lex(&lex1);
	tmp = res;
	while ((lex = separate_lex(lexem)))
	{
		lex1 = lex;
		if (!expression(&(tmp->next), &lex))
			return (reset(&tmp, lexem, &lex1));
		free_lex(&lex1);
		tmp = tmp->next;
	}
	free_lex(lexem);
	return (res);
}

t_tree				*lexor_and_parsor(t_shell *shell, char **line)
{
	t_lex			*lex;

	while (!quot(shell, line))
		;
	if (*line && (lex = syntax_error(shell, *line)) != NULL)
	{
		return (make_parsing(&lex));
	}
	return (NULL);
}
