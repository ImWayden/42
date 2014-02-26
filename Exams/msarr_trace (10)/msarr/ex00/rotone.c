/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 14:59:23 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 17:59:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rotone(char *str)
{
	int		c;

	while (*str)
	{
		c = *str;
		if (*str == 'z' || *str == 'Z')
			c = c - 25;
		else if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
			c++;
		write(1, &c, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_rotone(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
