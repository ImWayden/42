/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:17:12 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:17:35 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

t_param		*get_all_obj(t_param *param, char **tab)
{
	int		i;

	i = 0;
	param->objet = NULL;
	param->spot = NULL;
	if (tab != NULL && tab[i] != NULL)
		get_general(param, tab, &i);
	if (tab[i] != NULL)
		param->objet = get_one_obj(param->objet, tab, &i);
	if (tab[i] != NULL)
		param->spot = get_one_spot(param->spot, tab, &i);
	return (param);
}
