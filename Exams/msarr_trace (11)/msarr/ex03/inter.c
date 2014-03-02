/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 10:53:36 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 11:16:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is(char *str, int c, int i)
{
	while (*str && i)
	{
		if (*str == c)
			return (1);
		i--;
		str++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_inter(char *s1, char *s2)
{
	int		i;
	char	*str;

	str = s1;
	i = 0;
	while (*s1 && *s2)
	{
		if (!ft_is(str, *s1, i) && ft_is(s2, *s1, ft_strlen(s2)))
		   write(1, s1, 1);
 		s1++;
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
