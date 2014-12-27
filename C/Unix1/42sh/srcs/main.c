/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/11/15 12:08:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "grammar.h"
#include "42sh.h"

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

	if (ac != 1)
		ft_putendl("Usage: ./42sh");
	else
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
			line = get_line(shell, 0, 0);
			if ((shell->tree = lexor_and_parsor(shell, &line)))
			{
				ft_memdel((void **)&line);
				main_execution(&shell);
			}
		}
	}
	return (0);
}
