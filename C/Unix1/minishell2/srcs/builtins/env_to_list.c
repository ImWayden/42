/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:39:31 by msarr             #+#    #+#             */
/*   Updated: 2014/11/10 20:23:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

t_env			*env_listnew(char **str)
{
	t_env		*list;

	if ((list = (t_env *)malloc(sizeof(t_env))))
	{
		if (str)
			list->name = ft_strdup(str[0]);
		if (str)
			list->arg = ft_strdup(str[1]);
		list->next = NULL;
	}
	return (list);
}

t_env			*add_env_list(t_env *list, char **str)
{
	t_env		*tmp;
	t_env		*tmp1;

	tmp = env_listnew(str);
	if (!list)
		return (tmp);
	else
	{
		tmp1 = list;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
	}
	return (list);
}

t_env			*env_to_list(char **env)
{
	t_env		*list;
	char		**args;
	int			i;

	i = 0;
	list = NULL;
	while (env && env[i])
	{
		args = ft_strsplit(env[i], '=');
		list = add_env_list(list, args);
		ft_deltab(&args);
		i++;
	}
	return (list);
}
