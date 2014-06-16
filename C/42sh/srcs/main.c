/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/13 18:35:03 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int				main(int ac, char **av)
{
	//t_env		*envs;
	char		*line;
	t_lex		*list;

	if (ac != 1)
		ft_putendl("Usage: ./42sh");
	else
	{
		av++;
		line = NULL;
		list = NULL;
		get_next_line(1, &line);
		list = syntax_error(line);
		while (list)
		{
			ft_putendl(list->str);
			list = list->next;
		}
	}
	return (0);
}