/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/24 23:07:58 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_42sh.h"

int				main(int ac, char **av, char **envp)
{
	char		*buff;
	char		**envs;

	if ((envs = ft_getenv(envp)) && envp[0] == NULL)
	{
		ft_print_error("Empty env. Can't proceed to start the shell.");
		exit(1);
	}
	if (ac != 1)
		ft_print_error("Usage: ./42sh");
	if (ac == 1)
		ft_welcome();
	while (ac == 1)
	{
		ft_prompt(envs);
		ft_get_next_line(0, &buff);
		if (ft_strlen(buff) > 0 && ft_check(buff) == -1)
		{
			av = ft_strsplit(ft_strtrim(buff), ' ');
			ft_get_exit(av);
			ft_getcmd(av, &envs);
		}
	}
	return (0);
}