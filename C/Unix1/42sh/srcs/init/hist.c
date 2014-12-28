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

#include "shell.h"

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

int				hist_init(t_shell *shell)
{
	char		*str;
	int			fd;

	str = ft_strjoin(shell->pwd, shell->h_file);
	fd = open(str, O_RDWR);
	ft_memdel((void **)&str);
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
	return (0);
}
