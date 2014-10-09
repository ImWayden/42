/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 12:47:05 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:41:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static void			ft_prompt(t_shell *shell)
{
	char		*str;
	char		*str1;

	ft_putstr(shell->prompt);
	ft_putstr(":");
	if ((str = get_env(shell->env, "PWD")))
	{
		str1 = &((ft_strrchr(str, '/'))[1]);
		ft_putstr(str1);
		ft_memdel((void *)&str);
	}
	ft_putstr("$ ");
}

void			shell(char **env)
{
	char		*cmd = NULL;
	t_shell		*shell;

	shell = init(env);
	while (shell)
	{
		ft_prompt(shell);
		get_next_line(0, &cmd);
		if (shell->env && (shell->cmd = ft_strsplit(cmd, ' ')))
		{
			if (is_builtin((shell->cmd)[0]))
				builtins_center(&shell);
			else
				exec_cmd(shell);
		}
		ft_memdel((void **)&cmd);
		ft_deltab(&(shell->cmd));
	}
}

int					main(int argc, char **argv, char **env)
{
	if (argc == 1)
		shell(env);
	else
	{
		write(1, argv[0], ft_strlen(argv[0]));
		write(1, " : need to be executed without argument.\n", 41);
	}
	return (0);
}
