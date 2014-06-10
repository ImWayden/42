/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:03:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/08 03:15:55 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

static char			*get_cd_path(char **av, char **env, char *str)
{
	int				i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], str))
		{
			av[1] = ft_strsub(env[i], ft_strlen(str),
						(ft_strlen(env[i]) - ft_strlen(str)));
			return (av[1]);
		}
		i++;
	}
	return (NULL);
}

static char			*ft_get_pwd_path(char **envs, char *name)
{
	int				i;

	i = 0;
	while (envs[i])
	{
		if (ft_strstr(envs[i], ft_strjoin(name, "="))
			&& !ft_strstr(envs[i], "OLDPWD="))
			return (ft_strsub(envs[i], ft_strlen(name) + 1,
					ft_strlen(envs[i])));
		i++;
	}
	return (NULL);
}

static int			ft_get_pwd(char **envs)
{
	int				i;

	i = 0;
	while (envs[i])
	{
		if (ft_strstr(envs[i], "PWD=") && !ft_strstr(envs[i], "OLDPWD="))
			break ;
		i++;
	}
	return (i);
}

char				**cd_builtin(char **av, char **envs)
{
	int				i;
	char			*buff;

	i = ft_get_pwd(envs);
	if (av[1] == NULL || !ft_strcmp(av[1], "~") || !ft_strcmp(av[1], "~/"))
		av[1] = get_cd_path(av, envs, "HOME=");
	else if (!ft_strcmp(av[1], "-"))
		av[1] = get_cd_path(av, envs, "OLDPWD=");
	if (chdir(av[1]) == -1)
		ft_print_error("cd : No such file or directory.");
	else
	{
		setenv_builtin(envs, "OLDPWD", ft_get_pwd_path(envs, "PWD"));
		buff = getcwd(NULL, 0);
		envs[i] = ft_strsub(envs[i], 0, 4);
		envs[i] = ft_strjoin(envs[i], buff);
		free(buff);
	}
	return (envs);
}
