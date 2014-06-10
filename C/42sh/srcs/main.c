/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/09 15:04:20 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int				main(int ac, char **av, char **envp)
{
	t_env		*envs;

	if (ac != 1)
		ft_putendl("Usage: ./42sh");
	else
	{
		av++;
		ft_putendl("ok");
		envs = env_to_list(envp);
		aff_env(envs);
	}
	return (0);
}