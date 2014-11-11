/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limit_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:03:06 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:06:23 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	check_limit_while(char **tab, int *i)
{
	if (ft_strcmp(tab[*i], "<SPOT>") != 0
		&& ft_strcmp(tab[*i], "<SPHERE>") != 0
		&& ft_strcmp(tab[*i], "<PLAN>") != 0
		&& ft_strcmp(tab[*i], "<CYLINDRE>") != 0
		&& ft_strcmp(tab[*i], "<CONE>") != 0
		&& ft_strcmp(tab[*i], "<PARABOLOIDE>") != 0
		&& ft_strcmp(tab[*i], "<HYPERBOLOIDE>") != 0
		&& ft_strcmp(tab[*i], "<POS>") != 0
		&& ft_strcmp(tab[*i], "<COL>") != 0
		&& ft_strcmp(tab[*i], "<ROT>") != 0
		&& ft_strcmp(tab[*i], "<SIZE>") != 0
		&& ft_strcmp(tab[*i], "<BRILL>") != 0
		&& ft_strcmp(tab[*i], "<LIM>") != 0
		&& ft_strcmp(tab[*i], "<MIDDLE>") != 0
		&& ft_strcmp(tab[*i], "<PERTURB>") != 0)
		return (1);
	return (0);
}
