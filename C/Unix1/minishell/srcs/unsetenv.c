/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:27:41 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:27:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char				**ft_unsetenv(char **env, char *str)
{
	int				i;

	i = ft_isenv(env, str);
	while (env[i] && env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	if (i == -1)
		ft_putendl("unsetenv : wrong var env name.");
	else
	{
		free (env[i]);
		env[i] = NULL;
	}
	return (env);
}
