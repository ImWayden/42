/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:21:00 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:21:40 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

int		get_count_of_str(char *str)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (str[j])
	{
		if (str[j] == '<' || str[j] == '>' ||
			str[j] == 'X' || str[j] == 'R' ||
			str[j] == 'Y' || str[j] == 'G' ||
			str[j] == 'Z' || str[j] == 'B')
			count++;
		j++;
	}
	return (count);
}

char	*extract_str(char *str)
{
	int		j;
	int		k;
	int		count;
	char	*new;

	j = 0;
	k = 0;
	count = get_count_of_str(str);
	new = malloc(sizeof(*new) * (ft_strlen(str) - count + 1));
	while (str[j] != '\0')
	{
		if (str[j] != '<' && str[j] != '>'
			&& str[j] != 'X' && str[j] != 'R'
			&& str[j] != 'Y' && str[j] != 'G'
			&& str[j] != 'Z' && str[j] != 'B')
		{
			new[k] = str[j];
			k++;
		}
		j++;
	}
	new[k] = '\0';
	return (new);
}

void	get_a_a(t_param *param, char **tab, int *i)
{
	char	*new;

	(*i)++;
	new = extract_str(tab[*i]);
	if (tab[*i] && ft_strcmp(tab[*i], "<OBJ>") != 0
		&& ft_strcmp(tab[*i], "<SPOT>") != 0
		&& ft_strcmp(tab[*i], "<EYE>") != 0
		&& ft_strcmp(tab[*i], "<A.A>") != 0
		&& ft_strcmp(tab[*i], "<AMB>") != 0)
		param->anti_alias = ft_atoi(new);
	(*i)++;
	free(new);
}

void	get_amb(t_param *param, char **tab, int *i)
{
	char	*new;

	(*i)++;
	new = extract_str(tab[*i]);
	if (tab[*i] && ft_strcmp(tab[*i], "<OBJ>") != 0
		&& ft_strcmp(tab[*i], "<SPOT>") != 0
		&& ft_strcmp(tab[*i], "<EYE>") != 0
		&& ft_strcmp(tab[*i], "<A.A>") != 0
		&& ft_strcmp(tab[*i], "<AMB>") != 0)
		param->amb = atof(new);
	(*i)++;
	free(new);
}

void	get_general(t_param *param, char **tab, int *i)
{
	(*i)++;
	while (tab[*i] && ft_strcmp(tab[*i], "<OBJ>") != 0 &&
		ft_strcmp(tab[*i], "<SPOT>") != 0)
	{
		if (ft_strcmp(tab[*i], "<EYE>") == 0)
			get_eye(param, tab, i);
		else if (ft_strcmp(tab[*i], "<A.A>") == 0)
			get_a_a(param, tab, i);
		else if (ft_strcmp(tab[*i], "<AMB>") == 0)
			get_amb(param, tab, i);
	}
}
