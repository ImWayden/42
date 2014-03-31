/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:50:13 by msarr             #+#    #+#             */
/*   Updated: 2014/02/25 14:50:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

t_termlist		*ft_addlist(t_termlist *list, char *str)
{
	t_termlist	*tmp;

	tmp = (t_termlist *)malloc(sizeof(t_termlist));
	tmp->str = ft_strdup(str);
	tmp->next = NULL;
	tmp->prev = NULL;
	if (list)
	{
		tmp->next = list;
		list->prev = tmp;
	}
	return (tmp);
}

char	*ft_del(char *s1, int n)
{
	char		*str;
	int			i;
	int			j;

	if (n < 0)
		n = n * -1;
	i = ft_strlen(s1);
	if (n >= i)
		return(s1);
	str = ft_strnew(i - 1);
	j = 0;
	if (!n)
		s1[i - 1] = '\0';
	while (*s1 && str)
	{
		if ((j + n) != i)
		{
			str[j] = *s1;
			j++;
		}
		else
			i = 0;
		s1++;
	}
	return(str);
}

char	*ft_strnjoin(char *s1, char c, int n)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = 0;
	str = (char *) malloc(sizeof(char) * (i + 2));
	if (str)
		str[i + 1] = '\0';
	else
		return (NULL);
	k = i - n;
	i = 0;
	str[k] = c;
	while (s1[i])
	{
		if (j != k)
			str[j] = s1[i];
		else
			i--;
		i++;
		j++;
	}
	return (str);
}

char	*ft_join(char *s1, char *s2, int i)
{
	if (i < 0)
		i = i * -1;
	if (!i || !(*s2))
		return (ft_strjoin(s1, s2));
	else
		return (ft_strnjoin(s1, *s2, i));
}
