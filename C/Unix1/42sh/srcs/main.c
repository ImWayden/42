/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/12/28 01:00:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "grammar.h"
#include "shell.h"

void			ft_prompt(t_shell *shell)
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

int				main(int ac, char **av, char **env)
{
	t_shell		*shell;
	char		*line;

	if (ac == 1)
	{
		av++;
		line = NULL;
		shell = init(env);
		while (42)
		{
			re_init(shell);
			ft_prompt(shell);
			if (!shell->hist || (shell->hist->str && *shell->hist->str))
				new_hist(shell);
			else if (shell->hist && shell->hist->str)
				ft_memdel((void **)&shell->hist->str);
			line = get_line(shell, 0);
			if (line && (shell->tree = lexor_and_parsor(shell, &line)))
				main_execution(&shell);
		}
	}
	ft_putmsg(USAGE, NULL);
	return (0);
}
