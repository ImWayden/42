/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 12:47:05 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:41:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

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
