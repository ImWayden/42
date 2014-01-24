/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:10:03 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/24 14:49:45 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void		print_err(char *cmd, char *text)
{
	ft_putstr_fd("ft_minishell2: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(text, 2);
}

int			ft_strlen_ptr(char **av)
{
	int		i;

	i = 0;
	while (av[i][0])
		i++;
	return (i);
}

int			check_cmd(t_env *env, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env->tabPath[i])
	{
		tmp = env->tabPath[i];
		tmp = ft_strjoin(ft_strjoin(tmp, "/"), cmd);
		if (access(tmp, F_OK) == 0)
		{
			env->path = tmp;
			return (1);
		}
		i++;
	}
	return (-1);
}

void		get_path(t_env *env)
{
	char	*path;
	int		i;

	i = 0;
	while (env->environ[i])
	{
		if (ft_strnequ(env->environ[i], "PATH", 4) == 1)
			path = env->environ[i];
		i++;
	}
	i = 0;
	env->tabPath = ft_strsplit(&path[5], ':');
}
