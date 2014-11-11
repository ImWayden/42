/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:52:44 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:52:47 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

void	free_list(t_param *param)
{
	t_objet	*tmp;
	t_spot	*spot;

	tmp = param->objet;
	spot = param->spot;
	while (param->objet != NULL)
	{
		tmp = tmp->next;
		free(param->objet);
		param->objet = tmp;
	}
	while (param->spot != NULL)
	{
		spot = spot->next;
		free(param->spot);
		param->spot = spot;
	}
}
