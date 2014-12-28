/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:41:21 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 05:05:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "grammar.h"

int				save_infos(t_shell *shell)
{
	char		*str1;
	char		*str2;
	int			fd1;
	int			fd2;
	t_alias		*a;
	t_line		*h;
	void		*v;

	str1 = ft_strjoin(shell->pwd, shell->a_file);
	str2 = ft_strjoin(shell->pwd, shell->h_file);
	fd1 = open(str1, O_RDWR, O_CREAT | S_IRWXG);
	fd2 = open(str2, O_RDWR, O_CREAT | S_IRWXG);
	a = shell->alias;
	while (a)
	{
		write(fd1, a->name, ft_strlen(a->name));
		write(fd1, " ", 1);
		write(fd1, a->arg, ft_strlen(a->arg));
		write(fd1, "\n", 1);
		v = a;
		a = a->next;
		ft_memdel(v);
	}
	h = shell->hist;
	while (h)
	{
		write(fd2, h->str, ft_strlen(h->str));
		write(fd2, "\n", 1);
		v = h;
		h = h->next;
		ft_memdel(v);
	}
	close(fd1);
	close(fd2);
	return (1);
}

void			free_shell(t_shell **shell)
{
	if (shell && *shell)
	{
		save_infos(*shell);
		ft_memdel((void **)&(*shell)->prompt);
		ft_memdel((void **)&(*shell)->pwd);
		ft_deltab(&((*shell)->envc));
		ft_deltab(&(*shell)->path);
		free_env(&(*shell)->env);
		free_tree(&(*shell)->tree);
		ft_memdel((void **)shell);
	}
}
