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
		shell->envc = NULL;
		shell->tree = NULL;
	}
	return (shell);
}

t_shell				*init(char	**env)
{
	t_shell			*shell;

	if ((shell = shellnew()))
	{
		if ((shell->env = env_to_list(env)))
			shell->envc = list_to_tab(shell->env);
		if (!(shell->prompt = get_env(shell->env, "PATH")))
			shell->prompt = "~>";
		return (shell);
	}
	return (shell);
}


int					re_init(t_shell *shell)
{
	if (shell && shell->env)
	{
		//sleep(5);
		//ft_deltab(&(shell->envc));
		//sleep(5);
		shell->envc = list_to_tab(shell->env);
		ft_memdel((void **)&(shell->prompt));
		if (!(shell->prompt = get_env(shell->env, "PWD")))
			shell->prompt = "~>";
		return (1);
	}
	return (0);
}