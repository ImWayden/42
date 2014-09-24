/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:28:37 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:28:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int				ft_isenv(char **env, char *str)
{
	int			i;
	char		*str1;

	i = 0;
	while (env[i])
	{
		str1 = ft_strjoin(str, "=");
		if (ft_strnequ(str1, env[i], ft_strlen(str1)) == 1)
		{
			free(str1);
			return (i);
		}
		else
			i++;
		free(str1);
	}
	return (-1);
}
