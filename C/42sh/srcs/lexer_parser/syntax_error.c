/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/13 18:39:08 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

static t_lex	*set_error_msg(int flag, t_lex **lex)
{
	if (flag == 0)
		return (*lex);
	if (flag == 1)
		ft_putendl("Invalid null command.");
	else if (flag == 2)
		ft_putendl("Missing name for redirect.");
	else if (flag == 3)
		ft_putendl("Ambiguous input redirect.");
	else if (flag == 4)
		ft_putendl("Ambiguous output redirect.");
	free_lex(lex);
	return (NULL);
}

t_lex			*syntax_error(char *str)
{
	t_lex		*lex;
	int			flag;
	t_lex		*tmp;

	flag = 0;
	if (!(lex = lexer(str)))
		return (NULL);
	if (is_pipe(lex->str) || is_and_or_or_bin(lex->str))
		flag = 1;
	tmp = lex;
	while (tmp && flag == 0)
	{
		if (is_left_redir(tmp->str))
			flag = left_redir_syntax(tmp);
		else if (is_right_redir(tmp->str))
			flag = right_redir_syntax(tmp);
		else if (is_pipe(tmp->str) || is_and_or_or_bin(tmp->str))
			flag = pipe_and_or_syntax(tmp);
		tmp = tmp->next;
	}
	return (set_error_msg(flag, &lex));
}
