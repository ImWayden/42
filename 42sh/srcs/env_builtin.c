/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:01:29 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/23 19:03:13 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

static char			**ft_realenvs(char **envs, char *name, char *value)
{
	int				i;
	char			**tmp;

	tmp = envs;
	i = 0;
	while (tmp[i])
		i++;
	envs = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tmp[i])
	{
		envs[i] = ft_strdup(tmp[i]);
		i++;
	}
	envs[i] = ft_strjoin(name, "=");
	envs[i] = ft_strjoin(envs[i], value);
	envs[i + 1] = NULL;
	free(tmp);
	return (envs);
}

static char			**check_setenv_cmd(char **envs)
{
	int				i;

	i = 0;
	while (envs[i])
	{
		ft_putendl(envs[i]);
		i++;
	}
	return (envs);
}

char				**setenv_builtin(char **envs, char *name, char *value)
{
	int				i;

	if (name == NULL || value == NULL)
		envs = check_setenv_cmd(envs);
	else
	{
		i = 0;
		while (envs[i])
		{
			if (ft_strstr(envs[i], ft_strjoin(name, "=")))
			{
				envs[i] = ft_strsub(envs[i], 0, ft_strlen(name) + 1);
				envs[i] = ft_strjoin(envs[i], value);
				return (envs);
			}
			i++;
		}
		envs = ft_realenvs(envs, name, value);
	}
	return (envs);
}

char				**unsetenv_builtin(char **envs, char *name)
{
	int				i;
	int				j;
	char			**tmp;

	i = 0;
	while (envs[i])
		i++;
	tmp = envs;
	envs = malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	while (tmp[j])
	{
		if (ft_strstr(tmp[j], ft_strjoin(name, "=")) == NULL)
		{
			envs[i] = ft_strdup(tmp[j]);
			i++;
		}
		j++;
	}
	free(tmp);
	return (envs);
}