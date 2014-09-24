/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:28:01 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:28:04 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char			*ft_getenv(char **env, char *str)
{
	int			i;
	char		*str1;

	i = 0;
	while (env && env[i])
	{
		str1 = ft_strjoin(str, "=");
		if (ft_strnequ(str1, env[i], ft_strlen(str1)) == 1)
		{
			free(str1);
			return (ft_strdup(ft_strchr(env[i], '=') + 1));
		}
		else
			i++;
		free(str1);
	}
	return (NULL);
}
