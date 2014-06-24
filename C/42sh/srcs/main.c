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

#include "my_42sh.h"

static void			put_tree(t_tree *tree)
{
	if (tree)
	{
		put_tree(tree->left);
		put_tree(tree->right);
		ft_putnbr(tree->ope);
	}
}

int				main(int ac, char **av)
{
	//t_env		*envs;
	char		*line;
	t_tree		*tree;

	if (ac != 1)
		ft_putendl("Usage: ./42sh");
	else
	{
		av++;
		line = NULL;
		get_next_line(1, &line);
		if ((tree = lexor_and_parsor(line)))
			ft_putendl("OK");
		put_tree(tree);
	}
	return (0);
}