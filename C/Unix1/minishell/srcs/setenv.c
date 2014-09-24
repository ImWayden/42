/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:30:23 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 17:30:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char				**ft_setenv(char **env, char *str)
{
	int				i;
	char			**array;

	array = ft_strsplit(str, '=');
	if (array && array[0] && (i = ft_isenv(env, array[0])) > -1)
	{
		env[i] = array[1];
		return (env);
	}
	else
	{
		array = malloc(sizeof(char *) * (ft_tablen(env) + 2));
		array[ft_tablen(env) + 1] = NULL;
		i = 0;
		while (array && env && env[i])
		{
			array[i] = ft_strdup(env[i]);
			i++;
		}
		array[i] = str;
		ft_putendl(array[i]);
		return (array);
	}
}
