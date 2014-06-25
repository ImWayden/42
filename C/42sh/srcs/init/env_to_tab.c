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

#include "my_42sh.h"

static int		list_size(t_env *list)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

char		**list_to_table(t_env *env)
{
	int		i;
	char		**tab;
	int		j;

	j = 0;
	i = list_size(env);
	if (i == 0)
		return (NULL);
	if (!(tab = malloc((i + 1), sizeof(*board))))
    	return (NULL);
    while (env)
    {
    	tab[j++] = env->var;
    	env = env->next;
    }
    tab[j] = NULL;
    return (board);
}