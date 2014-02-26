/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/23 19:35:24 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int				main(int ac, char **av, char **envp)
{
	int			i;
	char		**buff;
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
		init(&buff, envs);
		i = 0;
		while (buff[i])
		{
			av = ft_strsplit(ft_strtrim(buff[i]), ' ');
			ft_get_exit(av);
			ft_getcmd(av, &envs);
			i++;
		}
	}
	return (0);
}