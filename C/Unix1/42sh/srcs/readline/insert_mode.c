/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 20:24:07 by msarr             #+#    #+#             */
/*   Updated: 2014/11/14 20:25:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void				insert_mode(char **str, int j, char c, char *buf)
{
	int				i;
	char			*str1;
	char			*str2;

	i = ft_strlen(*str) - j;
	str1 = *str;
	str2 = ft_strdup(&(str1[i]));
	str1[i] = c;
	str1[i + 1] = '\0';
	*str = ft_strjoin(str1, str2);
	ft_putstr(tgetstr("im", NULL));
	ft_putstr(buf);
	ft_putstr(tgetstr("ei", NULL));
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
}
