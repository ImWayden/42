/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 12:47:05 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 12:47:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

int main(int argc, char **argv, char **env)
{
	char	**envc;

	if (argc == 1)
	{
		envc = cp_env(env);
		if (*envc == '\0')
		{
			write(1, argv[0], ft_strlen(argv[0]));
			write(1, " : no environ.\n", 15);
			return 0;
		}
		shell(envc);
	}
	else
	{
		write(1, argv[0], ft_strlen(argv[0]));
		write(1, " : need to be executed without argument.\n", 41);
	}
	return 0;
}
