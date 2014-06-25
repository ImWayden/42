/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:07:34 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:07:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

int			execute_it(t_tree *tree, t_shell *st_shell)
{
	if (tree->type == IS_OR && execute_it(tree->left, st_shell) == EXIT_FAILURE)
		return (execute_it(tree->right, st_shell));
	if (tree->type == IS_AND && execute_it(tree->left, st_shell) == EXIT_SUCCESS)
		return (execute_it(tree->right, st_shell));
	else if (tree->type == IS_PIPE)
		return (execute_pipe_start(tree, st_shell));
	else if (tree->type == IS_CMD)
		return (execute_simple_command(tree, st_shell));
	else if (tree->type == IS_RIGHT || tree->type == IS_D_RIGHT)
		return (right_redirection(tree, st_shell));
	else if (tree->type == IS_LEFT || tree->type == IS_D_LEFT)
		return (left_redirection(tree, st_shell));
	return (EXIT_FAILURE);
}

void		main_execution(t_shell *st_shell)
{
	t_tree	*parse;
	int		flag;

	flag = 0;
	parse = st_shell->st_tree;
	while (flag == 0 && parse)
	{
		if (execute_it(parse, st_shell) == FATAL_ERROR)
		flag = 1;
		close_trees_fd(parse);
		parse = parse->next;
	}
	free_tree(st_shell->st_tree);
	t_shell->st_tree = NULL;
}