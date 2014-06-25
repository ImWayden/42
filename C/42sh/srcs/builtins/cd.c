/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:03:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/08 15:37:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int					cd(t_shell *shell, t_tree *tree)
{
	t_env			*envs;
	char			**av;
	char			*pwd;

	envs = shell->env;
	av = tree->argv;
	pwd = get_env(envs, "PWD");
	if (av[1] == NULL || !ft_strcmp(av[1], "~") || !ft_strcmp(av[1], "~/"))
		av[1] = get_env(envs, "HOME");
	else if (!ft_strcmp(av[1], "-"))
		av[1] = get_env(envs, "OLDPWD");
	if (chdir(av[1]) == -1)
	{
		ft_putmsg(av[1],": cd : No such file or directory.");
		return (EXIT_FAILURE);
	}
	//else
	//{
	//	ft_setenv(, pwd);
	//	ft_setenv(envs, "PWD", av[1]);
	//}
	return (EXIT_SUCCESS);
}
