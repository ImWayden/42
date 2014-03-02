/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 10:04:41 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 10:21:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_ulstr(char *str)
{
	int		c;

	while (*str)
	{
		c = *str;
		if (c >= 'a' && c <= 'z')
			c = c - 32;
		else if (c >= 'A' && c <= 'Z')
			c = c + 32;
		write(1, &c, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_ulstr(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
