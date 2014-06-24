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
#include "my_42sh.h"

int		execute_simple_pipe(t_tree *tree, t_shell *st_shell)
{
	int		fd[2];
	t_tree	*cmd;
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
		if (is_builtin(cmd->args[0]))
			exit(check_builtins(st_shell, cmd));
		close(fd[0]);
		if (dup2(cmd->fd_in, 0) == -1 || xdup2(cmd->fd_out, 1) == -1)
		exit(EXIT_FAILURE);
		execve(cmd->argv[0], cmd->args, st_shell->my_env);
	}
  	close(fd[1]);
	cmd->fd_out = 1;
	return (execution_chain(tree->left, st_shell));
}

void		init_first_pipe(t_tree *tree, t_shell *st_shell, int *fd)
{
	t_tree	*cmd;
 	pid_t		pid;

	cmd = tree->right;
	if ((pid = xfork()) < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		if (is_builtin(cmd->args[0]))
			exit(check_builtins(st_shell, cmd));
		close(fd[0]);
			if (xdup2(cmd->fd_in, 0) == -1 || xdup2(cmd->fd_out, 1) == -1)
		exit(EXIT_FAILURE);
		execve(cmd->full_path, cmd->args, st_shell->my_env);
	}
	close(fd[1]);
	cmd->fd_out = 1;
	if (execution_chain(tree->left, st_shell) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
  	exit(EXIT_SUCCESS);
}

void		init_first_pipe_spe(t_tree *tree, t_shell *st_shell, int *fd)
{
	t_tree	*cmd;
	pid_t		pid;

	if (spe_left(tree->right, st_shell) == EXIT_FAILURE || (pid = xfork()) == -1)
		exit(EXIT_FAILURE);
	cmd = tree->right->left;
	if (pid == 0)
	{
		if (is_builtin(cmd->args[0]))
			exit(check_builtins(st_shell, cmd));
		close(fd[0]);
		if (xdup2(cmd->fd_in, 0) == -1 || xdup2(cmd->fd_out, 1) == -1)
			exit(EXIT_FAILURE);
		execve(cmd->full_path, cmd->args, st_shell->my_env);
	}
	close(fd[1]);
	cmd->fd_out = 1;
	if (execution_chain(tree->left, st_shell) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}