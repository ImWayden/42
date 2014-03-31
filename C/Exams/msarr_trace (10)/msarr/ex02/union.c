/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 15:35:43 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 16:24:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_is_in(char *s1, int c)
{
	while (*s1)
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_erase(char *s1, int c)
{
	char	*tmp;
	int		i;

	tmp = s1;
	i = *tmp;
	while(*tmp)
	{
		if (*tmp == i)
			*tmp = c;
		tmp++;
	}
	return (s1);
}

int		ft_is_before(char *s1, char *s2, int c)
{
	while (s1 != s2)
	{
		s1--;
		if (*s1 == c)
			return (1);
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	while (*s1)
	{
		if (!ft_is_before(s1, tmp, *s1))
			write(1, s1, 1);
		s1++;
	}
	while (*s2)
	{
		if (!ft_is_in(tmp, *s2))
			write(1, s2, 1);
		s2 = ft_erase(s2, *tmp);
		s2++;
	}
	write(1, "\n", 1);
}

int     main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
