/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/16 12:35:04 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

static void		ft_prompt(t_shell *shell)
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

/*static void			put_tree(t_tree *tree)
{
	if (tree)
	{
		put_tree(tree->left);
		put_tree(tree->right);
		ft_puttab(tree->argv);
		put_tree(tree->next);
	}
}*/

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
			get_next_line(1, &line);
			if ((shell->tree = lexor_and_parsor(line)))
			{
				ft_memdel((void **)&line);
				main_execution(shell);
			}
		}
	}
	return (0);
}