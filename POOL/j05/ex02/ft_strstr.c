/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 14:04:02 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 14:04:04 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int					ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (s1 && s2 && *s1 && *s2 && n && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return (*s1 - *s2);
}

char				*ft_strstr(char *str, char *to_find)
{
	unsigned int	j;
	char			*tmp1;
	char			*tmp2;

	tmp1 = str;
	tmp2 = to_find;
	j = ft_strlen(tmp2);
	if (j == 0)
		return (tmp1);
	while (tmp1 && *tmp1 && (ft_strlen(tmp1) >= j))
	{
		if (ft_strncmp(tmp1, tmp2, j))
			tmp1++;
		else
			return (tmp1);
	}
	return (NULL);
}
