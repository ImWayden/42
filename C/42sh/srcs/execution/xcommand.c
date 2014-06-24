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


#include "grammar.h"
#include "my_42sh.h"

int     execute_simple_command(t_tree *tree, t_shell *st_shell)
{
	int     flag;
	int		statut;
	pid_t         pid;

	statut = 0;
	if (is_builtin(tree->args[0]))
		return (check_builtins(st_shell, tree));
	if (tree && (flag = prepare_command(tree, st_shell)) != EXIT_SUCCESS)
		return (flag);
	if ((pid = fork()) == 0)
	{
		reset_line(st_shell);
	 	dup2(tree->fd_in, 0);
		dup2(tree->fd_out, 1);
		execve(tree->args[0], tree->args, st_shell->my_env);
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &statut, 0) == -1)
			perror("Waitpid");
		return (write_statut(statut));
	}
	return (FATAL_ERROR);
}