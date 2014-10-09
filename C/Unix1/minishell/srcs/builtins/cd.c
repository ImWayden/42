/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:03:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/10/08 18:38:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static int			s_setenv(t_env **envs, char *name, char **arg)
{
	t_env			*envc;
	char			**args;

	envc = *envs;
	args = arg;
	if (envc)
	{
		if (args && args[0])
		{
			while (envc && envc->next && ft_strcmp(envc->name, name))
				envc = envc->next;
			if (envc && !ft_strcmp(envc->name, name))
			{
				ft_memdel((void **)&envc->arg);
				envc->arg = ft_strdup(args[0]);
			}
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static void			cd_get_path(char **av, char **path, char *pwd, char *str)
{
	char			*str1;

	if (!av[1])
		*path = ft_strdup(str);
	else if (!ft_strncmp(av[1], "~", 1))
		*path = ft_strjoin(str, &(av[1][1]));
	else if (!ft_strncmp(av[1], "/", 1))
		*path = ft_strdup(av[1]);
	else if (!ft_strcmp(av[1], "-"))
		*path = NULL;
	else if (!ft_strcmp(av[1], ".") || !ft_strcmp(av[1], ".."))
	{
		*path = ft_strdup(pwd);
		if (!ft_strcmp(av[1], ".."))
			(ft_strrchr(*path, '/'))[1] = '\0';
	}
	else
	{
		str1 = ft_strjoin(pwd, "/");
		*path = ft_strjoin(str1, av[1]);
		ft_memdel((void **)&str1);
	}
}

int					cd(t_shell *shell)
{
	t_env			*envs;
	char			**av;
	char			*pwd;
	char			*path;
	char			*home;

	envs = shell->env;
	av = shell->cmd;
	pwd = get_env(envs, "PWD");
	home = get_env(envs, "HOME");
	cd_get_path(av, &path, pwd, home);
	if (!path)
		path = get_env(envs, "OLDPWD");
	if (chdir(path) == -1)
		ft_putendl(": cd : No such file or directory.");
	else
	{
		s_setenv(&envs, "OLDPWD", &pwd);
		s_setenv(&envs, "PWD", &path);
	}
	ft_memdel((void **)&path);
	ft_memdel((void **)&pwd);
	ft_memdel((void **)&home);
	return (EXIT_SUCCESS);
}
