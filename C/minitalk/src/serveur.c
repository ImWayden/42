/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:40:24 by aleger            #+#    #+#             */
/*   Updated: 2014/02/09 02:14:01 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_slst
{
	char		c;
	struct s_slst *next;
}				t_slst;

static t_slst		*new_node(t_slst *node, char c)
{
	if (!node)
	{
		if (!(node = (t_slst *)malloc(sizeof(t_slst))))
			return (NULL);
		node->next = NULL;
		node->c = c;
	}
	else
		node->next = new_node(node->next, c);
	return (node);
}

static void			dump_list(t_slst **node)
{
	ft_putchar((*node)->c);
	if ((*node)->next)
		dump_list(&(*node)->next);
	free(*node);
	*node = NULL;
}

static void			catch_signal(int signal_sent)
{
	static char		current;
	static int		counter;
	static t_slst	*node = NULL;

	if (signal_sent == SIGUSR1)
		current += (1 << counter);
	++counter;
	if (counter > 7)
	{
		node = new_node(node, current);
		if (current == '\n')
		{
			dump_list(&node);
			node = NULL;
		}
		current = 0;
		counter = 0;
	}
}

int					main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, catch_signal);
	signal(SIGUSR2, catch_signal);
	while (1)
		pause();
	return (0);
}
