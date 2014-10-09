/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:04:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/24 22:25:37 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static int		list_size(t_env *list)
{
	int			i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

char			**list_to_tab(t_env *env)
{
	int			i;
	char		**tab1;
	char		*str;
	int			j;

	j = 0;
	i = list_size(env);
	if (i == 0)
		return (NULL);
	if (!(tab1 = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab1[i] = NULL;
	while (env)
	{
		str = ft_strjoin(env->name, "=");
		tab1[j] = ft_strjoin(str, env->arg);
		j++;
		env = env->next;
		ft_memdel((void **)&str);
	}
	return (tab1);
}
