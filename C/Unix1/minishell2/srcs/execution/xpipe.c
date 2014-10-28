/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:07:11 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:07:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

int				execute_last_command(t_tree *tree, t_shell *shell)
{
	int			statut;
	pid_t		pid;

	if (is_builtin(tree->argv[0]))
		return (builtins_center(shell, tree));
	if ((pid = fork()) == 0)
	{
		dup2(tree->fd[0], STDIN_FILENO);
		dup2(tree->fd[1], STDOUT_FILENO);
		execve(tree->argv[0], tree->argv, shell->envc);
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &statut, 0) == -1)
			perror("Waitpid() :");
		close(tree->fd[1]);
		return (write_statut(statut));
	}
	return (FATAL_ERROR);
}

int				execution_chain(t_tree *tree, t_shell *shell)
{
	if (tree->ope == IS_PIPE)
		return (execute_simple_pipe(tree, shell));
	else if (tree->ope == IS_CMD)
		return (execute_last_command(tree, shell));
	else if (tree->ope == IS_D_RIGHT || tree->ope == IS_RIGHT)
		return (execute_right_redir_spe(tree, shell));
	return (0);
}

int				execute_pipe_start(t_tree *tree, t_shell *shell)
{
	int			flag;
	int			statut;
	int			fd[2];
	pid_t		pid;

	if ((flag = prepare_all_commands(tree, shell)) != EXIT_SUCCESS)
		return (flag);
	if ((pid = fork()) == 0)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);
		set_fd_out(tree->right, fd[1]);
		set_fd_in(tree->left, fd[0]);
		if (tree->right->ope == IS_CMD)
			init_first_pipe(tree, shell, fd);
		init_first_pipe_spe(tree, shell, fd);
	}
	else if (pid > 0)
	{
		if (waitpid(-1, &statut, 0) == -1)
			perror("Waitpid() :");
		return (write_statut(statut));
	}
	return (FATAL_ERROR);
}
