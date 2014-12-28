/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcommand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:08:28 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:08:30 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "grammar.h"
#include "shell.h"

int				write_statut(int status)
{
	if (status == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int				execute_simple_command(t_tree *tree, t_shell **shell)
{
	int			flag;
	int			statut;
	pid_t		pid;

	statut = 0;
	if (is_builtin(tree->argv[0]))
		return (builtins_center(shell, tree));
	if (tree && (flag = prepare_command(tree, *shell)) != EXIT_SUCCESS)
		return (flag);
	if ((pid = fork()) == 0)
	{
		(*shell)->son = getpid();
		dup2(tree->fd[0], STDIN_FILENO);
		dup2(tree->fd[1], STDOUT_FILENO);
		if ((execve(tree->argv[0], tree->argv, (*shell)->envc)) == -1)
			perror(strerror(errno));
		exit(0);
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &statut, 0) == -1)
			ft_putmsg(WAITPID, NULL);
		return (write_statut(statut));
	}
	return (FATAL_ERROR);
}
