/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:03:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/08 15:37:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

int				is_builtin(char *cmd)
{
	if (!(ft_strcmp(cmd, "cd"))
	|| !(ft_strcmp(cmd, "unsetenv"))
	|| !(ft_strcmp(cmd, "setenv"))
	|| !(ft_strcmp(cmd, "env"))
	|| !(ft_strcmp(cmd, "pwd"))
	|| !(ft_strcmp(cmd, "exit")))
		return (1);
	return (0);
}

int				builtins_center(t_shell **shell, t_tree *tree)
{
	char		**argv;

	argv = tree->argv;
	if (argv && argv[0])
	{
		if (!(ft_strcmp(argv[0], "cd")))
			return (cd(*shell, tree));
		if (!(ft_strcmp(argv[0], "unsetenv")))
			return (ft_unsetenv(*shell, tree));
		if (!(ft_strcmp(argv[0], "setenv")))
			return (ft_setenv(*shell, tree));
		if (!(ft_strcmp(argv[0], "env")))
			return (aff_env(*shell, tree));
		if (!(ft_strcmp(argv[0], "exit")))
			ft_exit(shell);
		if (!(ft_strcmp(argv[0], "pwd")))
			ft_pwd(*shell);
	}
	return (EXIT_FAILURE);
}
