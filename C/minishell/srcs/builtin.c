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

#include "minishell2.h"

char				**ft_unsetenv(char **env, char *str)
{
	int				i;

	i = ft_isenv(env, str);
	while (env[i] && env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	if (i == -1)
		ft_putendl("unsetenv : wrong var env name.");
	else
	{
		free (env[i]);
		env[i] = NULL;
	}
	return (env);
}

char			*ft_getenv(char **env, char *str)
{
	int			i;
	char		*str1;

	i = 0;
	while (env[i])
	{
		str1 = ft_strjoin(str, "=");
		if (ft_strnequ(str1, env[i], ft_strlen(str1)) == 1)
		{
			free(str1);
			return (ft_strdup(ft_strchr(env[i], '=')));
		}
		else
			i++;
		free(str1);
	}
	return (NULL);
}

int				ft_isenv(char **env, char *str)
{
	int			i;
	char		*str1;

	i = 0;
	while (env[i])
	{
		str1 = ft_strjoin(str, "=");
		if (ft_strnequ(str1, env[i], ft_strlen(str1)) == 1)
		{
			free(str1);
			return (i);
		}
		else
			i++;
		free(str1);
	}
	return (-1);
}

void			ft_env_i(char ***env)
{
	char		**str;
	int			i;

	str = *env;
	i = 0;
	while (str && str[i])
	{
		ft_memdel((void **)&(str[i]));
		i++;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	ft_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
}

void	ft_changepwd(char **envc, char *pwd)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_getenv(envc, "PWD");
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
	char 	*buf;

	buf = ft_getenv(envc, "HOME");
	if (cmd)
	{
		cmd = ft_strtrim(cmd);
		if (*cmd == '~')
		{
			cmd++;
			if (cmd)
				cmd = ft_strjoin(buf, &cmd[1]);
			else
				cmd = buf;
		}
		else if (*cmd == '/')
			cmd = ft_strjoin(buf, cmd);
		else if (ft_strnequ("-", cmd, ft_strlen(cmd)) == 1)
			cmd = ft_getenv(envc, "OLDPWD");
		if (chdir(cmd) == -1)
		{
			ft_putendl("cd : No such file or directory");
			return ;
		}
	}
	else
	{
		chdir(buf);
		cmd = buf;
	}
	ft_changepwd(envc, cmd);
}
