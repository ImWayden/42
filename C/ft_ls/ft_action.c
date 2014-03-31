/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:54:24 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:31:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

int		ft_action(char **argv, int argc)
{
	int     i = 1;
	int		j = 0;
	t_list  *(*f1)(t_list *);
	t_list  *(*f2)(char *);
	void    (*f3)(t_list *, char *);
	void    (*f5) (char *, t_list *, t_list *(*)(t_list *), void (*)(t_list *),
			void (*)(t_list * , char *));
	void    (*f4) (char **, t_list *, t_list *(*)(t_list *), void (*)(t_list *),
			void (*)(t_list * , char *), t_list * (*)(char *));
	
	f1 = &ft_sortlist;
	f2 = &ft_recupdir;
	f3 = NULL;
	f5 = &ft_ls;
	f4 = NULL;
	while (argv[i] && i < argc - 1)
	{
		if (!ft_strcmp(argv[i], "-r"))
			f1 = &ft_rsortlist;
		else if (!ft_strcmp(argv[i], "-a"))
			f2 = &ft_arecupdir;
		else if (!ft_strcmp(argv[i], "-l"))
			f3 = &ft_put_ilist;
		else if (!ft_strcmp(argv[i], "-R"))
			f4 = &ft_ls_roption;
		else if (!ft_strcmp(argv[i], "-t"))
			j = 1;
		else
			return (0);
		i++;
	}
	if (j == 1)
	{
		if (f1 == &ft_sortlist)
			f1 = &ft_asortlist;
		else
			f1 = &ft_asortlist;
	}
	if (f4 == NULL)
	{
		if (f3 == NULL)
			f5(argv[argc - 1], f2(argv[argc - 1]), f1, &ft_put_list, NULL);
		else
			f5(argv[argc - 1], f2(argv[argc - 1]), f1, NULL, f3);
	}
	else
	{
		if (f3 == NULL)
			f4(&argv[argc - 1], f2(argv[argc - 1]), f1,&ft_put_list, NULL, f2);
		else
			f4(&argv[argc - 1], f2(argv[argc - 1]), f1, NULL, f3, f2);
	}
	return (1);
}
