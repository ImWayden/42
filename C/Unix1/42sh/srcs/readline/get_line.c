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

char					*get_line(t_shell *shell, int i)
{
	struct termios		term;
	char				*str;

	str = NULL;
	if (shell && shell->env && !ft_init(&term))
	{
		if (!ft_config(&term))
		{
			str = ft_term(shell, i, 0);
			if (ft_defconfig(&term))
				exit (0);
			return (str);
		}
	}
	get_next_line(1, &str);
	return (str);
}
