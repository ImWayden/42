/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 09:03:00 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

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
	return (tmp1);
}

static t_tree		*reset(t_tree **tree)
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

	t.i = 0;
	res = NULL;
	if ((lex = separate_lex(lexem)) && !expression(&res, lex))
		return (reset(res));
	tmp = res;
	while ((lex = separate_tree(lexem)))
	{
		if (!expression(&(tmp->next), lex))
			return (reset(tmp, board, len));
		tmp = tmp->next;
	}
	free_lex(lexem);
	return (res);
}
void		lexor_and_parsor(char *old, t_shell *st_shell)
{
  char		*new_line;
  char		**board;
  t_tree	*begin;

  if (check_if_line_is_valid(old) != -1)
    {
      begin = NULL;
      new_line = format_line(old);
      if (new_line && (board = check_syntax_error(new_line)) != NULL)
	{
	  begin = make_parsing(board);
	  st_shell->st_tree = begin;
	}
       free(new_line);
    }
  free(old);
}
