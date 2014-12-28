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

#include "shell.h"
#include "grammar.h"

int				save_hist(t_shell *shell)
{
	char		*str;
	int			fd;
	t_line		*h;

	str = ft_strjoin(shell->pwd, shell->h_file);
	fd = open(str, O_RDWR | O_CREAT, S_IXUSR | S_IWUSR | S_IRUSR);
	h = shell->hist;
	while (h && h->next)
		h = h->next;
	while (h && fd != -1)
	{
		write(fd, h->str, ft_strlen(h->str));
		write(fd, "\n", 1);
		h = h->prev;
	}
	close(fd);
	return (1);
}

int				save_alias(t_shell *shell)
{
	char		*str;
	int			fd;
	t_alias		*h;

	str = ft_strjoin(shell->pwd, shell->a_file);
	fd = open(str, O_RDWR | O_CREAT, S_IXUSR | S_IWUSR | S_IRUSR);
	h = shell->alias;
	while (h && fd != -1)
	{
		write(fd, h->name, ft_strlen(h->name));
		write(fd, " ", 1);
		write(fd, h->arg, ft_strlen(h->arg));
		write(fd, "\n", 1);
		h = h->next;
	}
	close(fd);
	return (1);
}

void			free_shell(t_shell **shell)
{
	if (shell && *shell)
	{
		save_hist(*shell);
		save_alias(*shell);
		ft_memdel((void **)&(*shell)->prompt);
		ft_memdel((void **)&(*shell)->pwd);
		ft_deltab(&((*shell)->envc));
		ft_deltab(&(*shell)->path);
		free_env(&(*shell)->env);
		free_tree(&(*shell)->tree);
		ft_memdel((void **)shell);
	}
}
