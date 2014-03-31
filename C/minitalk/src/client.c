/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:40:09 by aleger            #+#    #+#             */
/*   Updated: 2014/02/09 02:43:02 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static int						sig_abort(char *error, int ret)
{
	if (!ret)
	{
		ft_putendl_fd(error, STDERR_FILENO);
		ft_putendl_fd("Aborting", STDERR_FILENO);
	}
	return (ret);
}

static void						catch_signal(int signal_sent)
{
	(void)signal_sent;
}

static inline void				kill_pid_n(int pid_n, int usr)
{
	if (usr == 1)
	{
		if (kill(pid_n, SIGUSR1) == -1)
		{
			sig_abort("Signal error", 0);
			exit(0);
		}
	}
	else
	{
		if (kill(pid_n, SIGUSR2) == -1)
		{
			sig_abort("Signal error", 0);
			exit(0);
		}
	}
}

static int						send_to_server(char *pid_s, char *mes)
{
	int							pid_n;
	int							cur;
	char						mask;

	pid_n = ft_atoi(pid_s);
	mes = ft_strjoin(mes, "\n");
	cur = 0;
	if (mes)
	{
		while (mes[cur])
		{
			mask = 0;
			while (mask < 8)
			{
				if ((mes[cur] >> mask) & 1)
					kill_pid_n(pid_n, 1);
				else
					kill_pid_n(pid_n, 2);
				usleep(900);
				++mask;
			}
			++cur;
		}
	}
	return (sig_abort("Bad alloc", (mes) ? 1 : 0));
}

int								main(int ac, char **av)
{
	if (ac != 3)
		ft_putendl_fd("Wrong argument number. Expected 2", STDERR_FILENO);
	else
	{
		if (signal(SIGUSR1, catch_signal) == SIG_ERR
			|| signal(SIGUSR2, catch_signal) == SIG_ERR)
			return (sig_abort("Signal error", 0));
		else if (!send_to_server(av[1], av[2]))
			return (0);
	}
	return (0);
}
