/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 10:22:58 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 10:35:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_wdmatch(char *s1, char *s2)
{
	int		i;
	char	*str;

	str = s1;
	i = 0;
	while(*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			i++;
		}
		else
			s2++;

	}
	if (*s1 == '\0')
		write(1, str, i);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_wdmatch(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
