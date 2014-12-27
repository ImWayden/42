/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xright_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:10:43 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:10:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "42sh.h"

static int	open_file(char *name, int ope)
{
	int		fd;

	fd = -1;
	if (ope == IS_D_RIGHT)
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (ope == IS_RIGHT)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror("42sh : open");
	return (fd);
}

int			execute_right_redir_spe(t_tree *tree, t_shell **shell)
{
	int		fd;
	t_tree	*file;
	t_tree	*cmd;

	file = tree->right;
	cmd = tree->left;
	if (!file || !cmd)
		return (EXIT_FAILURE);
	if ((fd = open_file(file->argv[0], tree->ope)) == -1)
		return (EXIT_FAILURE);
	set_fd_out(cmd, fd);
	return (execute_last_command(tree->left, shell));
}

int			right_redirection(t_tree *tree, t_shell **shell)
{
	int		fd;
	t_tree	*file;
	t_tree	*cmd;

	file = tree->right;
	cmd = tree->left;
	if (!file || !cmd)
		return (FATAL_ERROR);
	if ((fd = open_file(tree->right->argv[0], tree->ope)) == -1)
		return (EXIT_FAILURE);
	set_fd_out(tree->left, fd);
	return (execute_it(tree->left, shell));
}
