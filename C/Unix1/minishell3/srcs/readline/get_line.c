/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:52:29 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 12:09:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

int						new_line(t_shell *shell, t_line **tmp)
{
	if ((*tmp = (t_line *)malloc(sizeof(t_line))))
	{
		(*tmp)->str = NULL;
		(*tmp)->prev = NULL;
		if (shell->hist)
			shell->hist->prev = *tmp;
		(*tmp)->next = shell->hist;
		shell->hist = *tmp;
		return (1);
	}
	return (0);
}

char					*get_line(t_shell *shell)
{
	struct termios		term;
	t_line				*tmp;

	new_line(shell, &tmp);
	if (shell && shell->env && !ft_init(&term))
	{
		if (!ft_config(&term))
		{
			ft_term(&tmp->str, shell, 0);
			if (!tmp->str || !tmp->str[0])
			{
				shell->hist = shell->hist->next;
				if (shell->hist)
					shell->hist->prev = NULL;
			}
			if (ft_defconfig(&term))
				exit (0);
			return (ft_strdup(tmp->str));
		}
	}
	get_next_line(1, &tmp->str);
	return (ft_strdup(tmp->str));
}
