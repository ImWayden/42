/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   satantua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/04 11:53:05 by msarr             #+#    #+#             */
/*   Updated: 2014/07/04 11:53:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			stairs(int i)
{
	if (i)
	{
		write(1, "/", 1);
		while (i)
		{
			write(1, "*", 1);
			i--;
		}
		write(1, "\\\n", 2);
	}
}

void			sastantua(int size)
{
	int			line;
	int			i;
	int			j;

	j = 3;
	i = 1;
	while (size)
	{
		line = j;
		while (line)
		{
			stairs(i);
			i++;
			while (!(i % 2))
				i++;
			line--;
		}
		i++;
		while (!(i % 2))
			i++;
		j++;
		size--;
	}
}

int			main(int argc, char **argv)
{
	sastantua(2);
	return (0);
}