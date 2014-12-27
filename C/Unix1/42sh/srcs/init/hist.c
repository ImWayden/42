/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:12:48 by msarr             #+#    #+#             */
/*   Updated: 2014/12/27 07:12:51 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int				new_hist(t_shell *shell)
{
	t_line		*tmp;

	if ((tmp = (t_line *)malloc(sizeof(t_line))))
	{
		tmp->str = NULL;
		tmp->prev = NULL;
		if (shell->hist)
			shell->hist->prev = tmp;
		tmp->next = shell->hist;
		shell->hist = tmp;
		return (1);
	}
	return (0);
}

int 			hist_init(t_shell *shell)
{
	char		*str;
	char		*str1;
	int			fd;

	if ((str = get_env(shell->env, "PWD")))
	{
		str1 = ft_strjoin(str, "/.hist");
		fd = open(str1, O_RDWR, O_CREAT);
		ft_memdel((void **)&str);
		ft_memdel((void **)&str1);
		if (fd != -1)
		{
			while (get_next_line(fd, &str))
			{
				if (new_hist(shell))
					shell->hist->str = str;
			}
			close(fd);
			return (1);
		}
	}
	ft_putendl("42sh : history load error");
	return (0);
}
