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

#include "my_42sh.h"

static t_shell		*shellnew(void)
{
	t_shell			*shell;

	if ((shell = (t_shell *)malloc(sizeof(t_shell))))
	{
		shell->env = NULL;
		shell->prompt = NULL;
		shell->path = NULL;
		shell->flag = 0;
	}
	return (shell);
}

t_shell				*init(char	**env)
{
	t_shell			*shell;

	if ((shell = shellnew()))
	{
		shell->env = env_to_list(env);
		shell->prompt = ft_strdup("~>");
		str = get_env(shell->env, "PWD");
		shell->path = ft_strsplit(str, ':');
		return (shell);
	}
	return (shell);
}
