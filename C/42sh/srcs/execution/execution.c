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

int			execute_it(t_tree *tree, t_shell *shell)
{
	if (tree->ope == IS_OR && execute_it(tree->left, shell) == EXIT_FAILURE)
		return (execute_it(tree->right, shell));
	if (tree->ope == IS_AND && execute_it(tree->left, shell) == EXIT_SUCCESS)
		return (execute_it(tree->right, shell));
	else if (tree->ope == IS_PIPE)
		return (execute_pipe_start(tree, shell));
	else if (tree->ope == IS_CMD)
		return (execute_simple_command(tree, shell));
	else if (tree->ope == IS_RIGHT || tree->ope == IS_D_RIGHT)
		return (right_redirection(tree, shell));
	else if (tree->ope == IS_LEFT || tree->ope == IS_D_LEFT)
		return (left_redirection(tree, shell));
	return (EXIT_FAILURE);
}

void		main_execution(t_shell *shell)
{
	t_tree	*parse;
	int		flag;

	flag = 0;
	parse = shell->tree;
	while (flag == 0 && parse)
	{
		if (execute_it(parse, shell) == FATAL_ERROR)
		flag = 1;
		close_trees_fd(parse);
		parse = parse->next;
	}
	free_tree(&shell->tree);
	shell->tree = NULL;
}