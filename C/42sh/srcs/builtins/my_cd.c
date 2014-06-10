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

int					**my_cd(char **av, t_env *envs)
{
	int				i;
	char			*buff;
	char			*pwd;

	pwd = get_env(envs, "PWD");
	if (av[1] == NULL || !ft_strcmp(av[1], "~") || !ft_strcmp(av[1], "~/"))
		av[1] = get_env(envs, "HOME"));
	else if (!ft_strcmp(av[1], "-"))
		av[1] = get_env(envs, "OLDPWD");
	if (chdir(av[1]) == -1)
	{
		ft_print_error("cd : No such file or directory.");
		return (0);
	}
	else
	{
		my_setenv(envs, "OLDPWD", pwd);
		my_setenv(envs, "PWD", av[1]);
	}
	return (1);
}
