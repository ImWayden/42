/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xleft_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:10:21 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:10:24 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

static int	_open_file(char *name)
{
	int		fd;

	if (access(name, F_OK) == -1 || access(name, R_OK) == -1)
	{
		if (access(name, F_OK) == -1)
			fprintf(stderr, "%s: no such file or directory.\n", name);
	 	else
			printf(stderr, "%s: don't have the permission to read file.\n", name);
	 	return (-1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		fprintf(stderr, "%s: Error : maybe targeted"
		"directory doesn't exist.\n", name);
	return (fd);
}

int		spe_left(t_tree *tree, t_shell *st_shell)
{
	int		fd;
	char		**args;

	(void)st_shell;
	args = tree->right->args;
	if (!args || !args[0] || (fd = _open_file(args[0])) == -1)
		return (EXIT_FAILURE);
	set_fd_in(tree->left, fd);
	return (EXIT_SUCCESS);
}

int		left_redirection(t_tree *tree, t_shell *st_shell)
{
	int		fd;
	char		**args;

	args = tree->right->args;
	if (!args || !args[0] || (fd = _open_file(args[0])) == -1)
		return (EXIT_FAILURE);
	set_fd_in(tree->left, fd);
	return (execute_it(tree->left, st_shell));
}