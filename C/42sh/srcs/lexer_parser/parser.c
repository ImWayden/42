/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 22:05:02 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

t_tree			*init_tree(void)
{
	t_tree		*tree;

	if ((tree = (t_tree *)malloc(sizeof(t_tree))))
	{
		tree->right = NULL;
		tree->left = NULL;
		tree->next = NULL;
		tree->argv = NULL;
	}
	return (tree);
}

t_lex			*separate_lex(t_lex **lex)
{
	t_lex		*tmp;
	t_lex		*tmp1;

	tmp = *lex;
	tmp1 = *lex;
	while (tmp && !is_semi_colon(tmp->str))
		tmp = tmp->next;
	if (tmp && is_semi_colon(tmp->str))
	{
		*lex = tmp->next;
		lex_delfirst(&tmp);
	}
	else
		*lex = NULL;
	return (tmp1);
}

static t_tree		*reset(t_tree **tree, t_lex **lexem)
{
	if (*tree)
		free_tree(tree);
	free_lex(lexem);
	return (NULL);
}

t_tree			*make_parsing(t_lex **lexem)
{
	t_lex		*lex;
	t_tree		*res;
	t_tree		*tmp;

	res = NULL;
	ft_putendl("ok");
	if ((lex = separate_lex(lexem)) && !expression(&res, &lex))
		return (reset(&res, lexem));
	free_lex(&lex);
	tmp = res;
	while ((lex = separate_lex(lexem)))
	{
		if (!expression(&(tmp->next), &lex))
			return (reset(&tmp, lexem));
		free_lex(&lex);
		tmp = tmp->next;
	}
	free_lex(lexem);
	return (res);
}

t_tree			*lexor_and_parsor(char *line)
{
	t_lex		*lex;

	if (line && (lex = syntax_error(line)) != NULL)
		return(make_parsing(&lex));
	return (NULL);
}
