/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/13 13:34:11 by msarr             #+#    #+#             */
/*   Updated: 2014/07/13 13:34:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			match(char *s1, char *s2)
{
	if (*s2 == '\0' && *s1 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s1 == '*' && *s2 == '*')
		return (match(s1 + 1, s2));
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (*s2 == '*')
	{
		s2++;
		while (*s1)
		{
			if (match(s1, s2) == 0)
				s1++;
			else
				return (1);
		}
		return (match(s1, s2));
	}
	else
		return (0);
}
