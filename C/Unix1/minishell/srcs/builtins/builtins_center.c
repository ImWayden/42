/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:03:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/10/08 18:11:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int				is_builtin(char *cmd)
{
	if (!(ft_strcmp(cmd, "cd"))
	|| !(ft_strcmp(cmd, "unsetenv"))
	|| !(ft_strcmp(cmd, "setenv"))
	|| !(ft_strcmp(cmd, "exit"))
	|| !(ft_strcmp(cmd, "env")))
		return (1);
	return (0);
}

int				builtins_center(t_shell **shell)
{
	char		**argv;

	argv = (*shell)->cmd;
	if (argv && argv[0])
	{
		if (!(ft_strcmp(argv[0], "cd")))
			return (cd(*shell));
		if (!(ft_strcmp(argv[0], "unsetenv")))
			return (ft_unsetenv(*shell));
		if (!(ft_strcmp(argv[0], "setenv")))
			return (ft_setenv(*shell));
		if (!(ft_strcmp(argv[0], "env")))
			return (aff_env(*shell));
		if (!(ft_strcmp(argv[0], "exit")))
			ft_exit(shell);
		if (!(ft_strcmp(argv[0], "pwd")))
			ft_pwd(*shell);
	}
	return (EXIT_FAILURE);
}
