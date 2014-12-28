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

#include "shell.h"

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

static void			ft_del(char **path, char **pwd, char **home)
{
	ft_memdel((void **)path);
	ft_memdel((void **)pwd);
	ft_memdel((void **)home);
}

static	int			cd_error(char **path, char *bin)
{
	if (access(*path, F_OK) == -1)
		ft_putmsg(bin, CD_DIR);
	else
		ft_putmsg(bin, CD_PERM);
	ft_memdel((void **)path);
	return (EXIT_FAILURE);
}

static	void		end_cd(t_shell *shell, char **path, char **pwd)
{
	int				i;

	while ((i = ft_strlen(*path)) && (*path)[i - 1] == '/')
		(*path)[i - 1] = '\0';
	s_setenv(&(shell->env), "OLDPWD", pwd);
	s_setenv(&(shell->env), "PWD", path);
}

int					cd(t_shell *shell, t_tree *tree)
{
	char			*pwd;
	char			*path;
	char			*home;

	if (cd_needed(shell, tree, &pwd, &home) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cd_get_path(tree->argv, &path, pwd, home);
	if (!path)
	{
		if (!(path = get_env(shell->env, "OLDPWD")))
		{
			ft_putmsg(CD_OLDPWD, NULL);
			return (EXIT_FAILURE);
		}
		ft_putendl(path);
	}
	if (chdir(path) == -1)
		return (cd_error(&path, tree->argv[1]));
	else
		end_cd(shell, &path, &pwd);
	ft_del(&path, &pwd, &home);
	return (EXIT_SUCCESS);
}
