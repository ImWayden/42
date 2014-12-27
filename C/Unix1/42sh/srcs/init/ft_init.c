/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:04:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/24 23:07:35 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static t_shell		*shellnew(void)
{
	t_shell			*shell;

	if ((shell = (t_shell *)malloc(sizeof(t_shell))))
	{
		shell->env = NULL;
		shell->prompt = NULL;
		shell->pwd = NULL;
		shell->alias = NULL;
		shell->hist = NULL;
		shell->path = NULL;
		shell->envc = NULL;
		shell->tree = NULL;
	}
	return (shell);
}

t_shell				*init(char **env)
{
	t_shell			*shell;

	if ((shell = shellnew()))
	{
		if ((shell->env = env_to_list(env)))
			shell->envc = list_to_tab(shell->env);
		if (!(shell->prompt = get_env(shell->env, "USER")))
			shell->prompt = ft_strdup("~>");
		shell->pwd = get_env(shell->env, "PWD");
		hist_init(shell);
		alias_init(shell);
		return (shell);
	}
	return (shell);
}

int					re_init(t_shell *shell)
{
	char			*str;

	if (shell && shell->env)
	{
		ft_deltab(&(shell->envc));
		shell->envc = list_to_tab(shell->env);
		ft_memdel((void **)&(shell->prompt));
		if (!(shell->prompt = get_env(shell->env, "USER")))
			shell->prompt = ft_strdup("~>");
		ft_deltab(&shell->path);
		str = get_env(shell->env, "PATH");
		shell->path = ft_strsplit(str, ':');
		ft_memdel((void *)&str);
		return (1);
	}
	return (0);
}
