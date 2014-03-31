/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 03:00:29 by msarr             #+#    #+#             */
/*   Updated: 2013/12/31 03:00:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int argc, char  **argv)
{
	pid_t		father;
	char 		**str;
	int			tube[2];
	int			fd;

	pipe(tube);
	father = fork();
	if (argc == 5)
	{
		if (father > 0)
		{
			wait(NULL);
			return (ft_father(argv, str, fd, tube));
		}
		if (father == 0)
			return (ft_son(argv, str, fd, tube));
	}
	return 0;
}
