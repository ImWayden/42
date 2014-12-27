/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipe2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:08:56 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:08:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "42sh.h"

int				execute_simple_pipe(t_tree *tree, t_shell **shell)
{
	int			fd[2];
	t_tree		*cmd;
	pid_t		pid;

	cmd = tree->right;
	if (pipe(fd) == -1)
		return (FATAL_ERROR);
	set_fd_out(tree->right, fd[1]);
	set_fd_in(tree->left, fd[0]);
	if ((pid = fork()) < 0)
		return (FATAL_ERROR);
	if (pid == 0)
	{
		if (is_builtin(cmd->argv[0]))
			exit(builtins_center(shell, cmd));
		close(fd[0]);
		if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
			exit (EXIT_FAILURE);
		execve(cmd->argv[0], cmd->argv, (*shell)->envc);
	}
	close(fd[1]);
	cmd->fd[1] = 1;
	return (execution_chain(tree->left, shell));
}

void			init_first_pipe(t_tree *tree, t_shell **shell, int *fd)
{
	t_tree		*cmd;
	pid_t		pid;

	cmd = tree->right;
	if ((pid = fork()) < 0)
		exit (EXIT_FAILURE);
	if (pid == 0)
	{
		if (is_builtin(cmd->argv[0]))
			exit (builtins_center(shell, cmd));
		close(fd[0]);
		if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
			exit(EXIT_FAILURE);
		execve(cmd->argv[0], cmd->argv, (*shell)->envc);
	}
	close(fd[1]);
	cmd->fd[1] = 1;
	if (execution_chain(tree->left, shell) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void			init_first_pipe_spe(t_tree *tree, t_shell **shell, int *fd)
{
	t_tree		*cmd;
	pid_t		pid;

	if (spe_left(tree->right, shell) == EXIT_FAILURE || (pid = fork()) == -1)
		exit(EXIT_FAILURE);
	cmd = tree->right->left;
	if (pid == 0)
	{
		if (is_builtin(cmd->argv[0]))
			exit(builtins_center(shell, cmd));
		close(fd[0]);
		if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
			exit(EXIT_FAILURE);
		execve(cmd->argv[0], cmd->argv, (*shell)->envc);
	}
	close(fd[1]);
	cmd->fd[0] = 1;
	if (execution_chain(tree->left, shell) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
