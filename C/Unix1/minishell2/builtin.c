/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 01:06:32 by msarr             #+#    #+#             */
/*   Updated: 2014/01/26 01:06:42 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell2.h"

char		**ft_unsetenv(char **env, char *str)
{
	int		i;

	i = ft_isenv(env, str);
	while (env[i] && env[i + 1])
	{
		free (env[i]);
		env[i] = ft_strdup(env[i + 1]);
		i++;
	}
	if (i == -1)
		print_err("unsetenv", " : wrong var env name.");
	else
	{
		free (env[i]);
		env[i] = NULL;
	}
	return (env);
}

int		ft_isenv(char **env, char *str)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(ft_strjoin(str, "="), env[i], (ft_strlen(str) + 1))
			== 1)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_env_i(char ***env)
{
	ft_memdel((void **)*env);
}

void	ft_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		ft_putendl_fd(env[i++], 1);
}

void	ft_changepwd(char **envc, char *pwd)
{
	int		i;
	char	*str;

	i = 0;
	str = (get_env(envc, "PWD"))[0];
	while (envc[i])
	{
		if (ft_strnequ("PWD=", envc[i], 4) == 1)
			envc[i] = ft_strjoin("PWD=", pwd);
		else if (ft_strnequ("OLDPWD=", envc[i], 7) == 1)
			envc[i] = ft_strjoin("OLDPWD=", str);
		i++;
	}
}

void	ft_cd(char **envc, char *cmd)
{
	char 	**buf;

	buf = get_env(envc, "HOME");
	if (cmd)
	{
		cmd = ft_strtrim(cmd);
		if (*cmd == '~')
		{
			cmd++;
			if (cmd)
				cmd = ft_strjoin(*buf, &cmd[1]);
			else
				cmd = *buf;
		}
		else if (*cmd == '/')
			cmd = ft_strjoin(*buf, cmd);
		else if (ft_strnequ("-", cmd, ft_strlen(cmd)) == 1)
			cmd = (get_env(envc, "OLDPWD"))[0];
		if (chdir(cmd) == -1)
		{
			print_err("cd", "No such file or directory");
			return ;
		}
	}
	else
	{
		chdir(*buf);
		cmd = *buf;
	}
	ft_changepwd(envc, cmd);
}