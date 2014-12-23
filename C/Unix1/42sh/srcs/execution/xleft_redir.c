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
#include "minishell3.h"

void			ft_putmsg(char *name, char *msg)
{
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

static int		open_file(char *name)
{
	int			fd;

	if (access(name, F_OK) == -1 || access(name, R_OK) == -1)
	{
		if (access(name, F_OK) == -1)
			ft_putmsg(name, ": no such file or directory.\n");
		else
			ft_putmsg(name, ": don't have the permission to read file.\n");
		return (-1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_putmsg(name, ": Error: maybe targeted directory doesn't exist.\n");
	return (fd);
}

int				spe_left(t_tree *tree, t_shell **shell)
{
	int			fd;
	char		**args;

	(void)shell;
	args = tree->right->argv;
	if (!args || !args[0] || (fd = open_file(args[0])) == -1)
		return (EXIT_FAILURE);
	set_fd_in(tree->left, fd);
	return (EXIT_SUCCESS);
}

int				left_redirection(t_tree *tree, t_shell **shell)
{
	int			fd;
	char		**args;

	args = tree->right->argv;
	if (!args || !args[0] || (fd = open_file(args[0])) == -1)
		return (EXIT_FAILURE);
	set_fd_in(tree->left, fd);
	ft_putendl(tree->left->argv[0]);
	return (execute_it(tree->left, shell));
}
