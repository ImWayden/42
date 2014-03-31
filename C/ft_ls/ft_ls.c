/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:55:58 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:38:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void	ft_ls(char *dir, t_list *mylist, t_list *(*f)(t_list *),
		void (*f1)(t_list *), void (*f2)(t_list *, char *))
{
	mylist = f(mylist);
	if (!f2)
		f1(mylist);
	else
		f2(mylist, dir);
}
