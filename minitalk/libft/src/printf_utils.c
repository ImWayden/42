/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 18:07:55 by aleger            #+#    #+#             */
/*   Updated: 2014/01/26 09:48:24 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char					*format_mod(char *s)
{
	int					i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '%')
				s[i] = 5;
		}
		i++;
	}
	return (s);
}

char					*ft_uitoa(unsigned int n)
{
	char				s[50];
	unsigned int		i;

	if (!n)
		return (ft_strdup("0"));
	i = 0;
	while (n != 0)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	s[i] = '\0';
	return (ft_strdup(ft_strrev(s)));
}

char					*ft_uotoa(unsigned int n)
{
	char				s[50];
	unsigned int		i;

	if (!n)
		return (ft_strdup("0"));
	i = 0;
	while (n != 0)
	{
		s[i] = (n % 8) + 48;
		n /= 8;
		i++;
	}
	s[i] = '\0';
	return (ft_strdup(ft_strrev(s)));
}

char					*ft_xtoa(unsigned int n)
{
	char				s[16];
	int					i;

	if (!n)
		return (ft_strdup("0"));
	i = 0;
	while (n != 0)
	{
		s[i] = (((n % 16) > 9) ? ((n % 16) + 87) : ((n % 16) + 48));
		i++;
		n /= 16;
	}
	s[i] = '\0';
	return (ft_strdup(ft_strrev(s)));
}
