/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:58:54 by aleger            #+#    #+#             */
/*   Updated: 2014/01/23 01:20:27 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		nb_words(char const *s, char c)
{
	int			count;
	int			state;

	state = OUT;
	count = 0;
	while (*s)
	{
		if (state == OUT && *s != c)
		{
			state = IN;
			++count;
		}
		if (state == IN && *s == c)
			state = OUT;
		++s;
	}
	return (count);
}

static void		copy_into_array(char **array, char const *s, char c)
{
	int			state;
	int			beginning_word;
	int			i;

	state = OUT;
	i = 0;
	while (s[i])
	{
		if (state == OUT && s[i] != c)
		{
			state = IN;
			beginning_word = i;
		}
		if (state == IN && s[i] == c)
		{
			state = OUT;
			*array = ft_strsub(s, beginning_word, i - beginning_word);
			++array;
		}
		++i;
	}
	if (state == IN)
		*array = ft_strsub(s, beginning_word, i - beginning_word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	int			nb;

	nb = nb_words(s, c) + 1;
	ret = (char **) malloc(nb * sizeof(char *));
	if (ret)
	{
		copy_into_array(ret, s, c);
		ret[nb - 1] = 0;
	}
	return (ret);
}
