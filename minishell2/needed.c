/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:06:13 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 17:06:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell2.h"

void		print_err(char *cmd, char *text)
{
	ft_putstr_fd("ft_minishell2: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(text, 2);
}

int			ft_strlen_ptr(char **av)
{
	int		i;

	i = 0;
	while (av[i][0])
		i++;
	return (i);
}

int			check_cmd(char **path, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = path[i];
		tmp = ft_strjoin(ft_strjoin(tmp, "/"), cmd);
		if (access(tmp, F_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**get_path(char	**env)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], "PATH", 4) == 1)
			path = env[i];
		i++;
	}
	i = 0;
	//write(1, *path, ft_strlen(*path));
	return (ft_strsplit(&path[5], ':'));
}
