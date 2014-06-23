/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:07:33 by msarr             #+#    #+#             */
/*   Updated: 2014/02/25 12:07:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

char	*ft_edit(t_termlist *list, char **envc)
{
	struct termios		term;
	char				*buffer;
	char				*str;
	int					i;

	if (ft_init(&term))
		return (NULL);
	if (ft_config(&term))
		return (NULL);
	str = ft_strdup(list->str);
	i = 0;
	while (1)
	{
		buffer = ft_put(i, str, envc);
		list = ft_choice(buffer, list, &str, &i);
		if (!list)
		{
			ft_putstr("\n");
			break;
		}
	}
	ft_defconfig(&term);
	return (str);
}

void	init(char ***cmd, char **envc)
{
	char		*str;
	static t_termlist		*list = NULL;

	if (!list || *(list->str))
		list = ft_addlist(list, "\0");
	str = ft_edit(list, envc);
	list->str = ft_strjoin(list->str, str);
	str = ft_strtrim(str);
	*cmd = ft_strsplit(str, ';');
}
