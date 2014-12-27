/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:12:10 by msarr             #+#    #+#             */
/*   Updated: 2014/12/27 07:12:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int				new_alias(t_shell *shell, char **str)
{
	t_alias		*tmp;

	if ((tmp = (t_alias *)malloc(sizeof(t_alias))))
	{
		tmp->name = ft_strdup(str[0]);
		tmp->arg = ft_strdup(str[1]);
		tmp->prev = NULL;
		if (shell->alias)
			shell->alias->prev = tmp;
		tmp->next = shell->alias;
		shell->alias = tmp;
		return (1);
	}
	return (0);
}

int 			set_alias(t_shell *shell, char **argv)
{
	if (argv && *argv && argv[1])
	{
		new_alias(shell, argv);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

char 			*get_alias(t_shell *shell, char *str)
{
	t_alias		*a;

	a = shell->alias;
	while (a && str)
	{
		if (!ft_strcmp(a->name, str))
			return (ft_strdup(a->arg));
		a++;
	}
	return (NULL);
}

int 			alias_init(t_shell *shell)
{
	char		*str;
	char		**al;
	int			fd;

	if (shell->pwd)
	{
		str = ft_strjoin(shell->pwd, "/.alias");
		fd = open(str, O_RDWR, O_CREAT);
		ft_memdel((void **)&str);
		if (fd != -1)
		{
			while (get_next_line(fd, &str))
			{
				al = ft_strsplit(str, '=');
				new_alias(shell, al);
				ft_deltab(&al);
			}
			close(fd);
			return (1);
		}
	}
	ft_putendl("42sh : alias load error");
	return (0);
}