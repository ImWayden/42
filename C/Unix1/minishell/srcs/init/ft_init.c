/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:04:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/10/08 18:40:04 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static t_shell		*shellnew(void)
{
	t_shell			*shell;

	if ((shell = (t_shell *)malloc(sizeof(t_shell))))
	{
		shell->env = NULL;
		shell->envc = NULL;
		shell->prompt = NULL;
		shell->path = NULL;
		shell->flag = 0;
	}
	return (shell);
}

t_shell				*init(char	**env)
{
	t_shell			*shell;
	char			*str;

	if ((shell = shellnew()))
	{
		shell->env = env_to_list(env);
		shell->envc = env;
		shell->prompt = ft_strdup("~>");
		str = get_env(shell->env, "PATH");
		shell->path = ft_strsplit(str, ':');
		return (shell);
	}
	return (shell);
}
