/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
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

=======
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

	
>>>>>>> fc382db9c32f12bfa015c589a3e35834beacc415
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
<<<<<<< HEAD
		ft_prompt(envs);
		ft_get_next_line(0, &buff);
		if (ft_strlen(buff) > 0 && ft_check(buff) == -1)
		{
			av = ft_strsplit(ft_strtrim(buff), ' ');
			ft_get_exit(av);
			ft_getcmd(av, &envs);
=======
		init(&buff, envs);
		i = 0;
		while (buff[i])
		{
			av = ft_strsplit(ft_strtrim(buff[i]), ' ');
			ft_get_exit(av);
			ft_getcmd(av, &envs);
			i++;
>>>>>>> fc382db9c32f12bfa015c589a3e35834beacc415
		}
	}
	return (0);
}