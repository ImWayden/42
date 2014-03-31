/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsroption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:56:13 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:42:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void	ft_ls_roption(char **dir, t_list *mylist, t_list *(*f)(t_list *),
		void (*f1)(t_list *), void (*f2)(t_list *, char *),
		t_list *(*f3)(char *))
{
	DIR *dp;
	t_list   *tmp;
	t_list  *tmp1;
	char *str;
	
	ft_ls(*dir, mylist, f, f1,f2);
	tmp = f(mylist);
	while (tmp)
	{
		if ((dp = opendir(ft_strjoin(ft_strjoin(*dir, "/"), tmp->str))) != NULL)
		{
			closedir(dp);
			str = ft_strjoin(ft_strjoin(*dir, "/"), tmp->str);
			tmp1 = f3(str);
			if (tmp1 && ft_strcmp(tmp->str, ".") != 0 && ft_strcmp(tmp->str, "..") != 0)
				ft_ls_roption(&str, tmp1, f, f1, f2, f3);
			else
			{
				ft_putdir((char *)str);
				ft_putdir(tmp->str);
				ft_putstr("\n");
			}
		}
		tmp = tmp->next;
	}
}
