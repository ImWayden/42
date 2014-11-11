/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:52:37 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:52:40 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	count_obj(t_param *param)
{
	int		i;
	t_objet *tmp;

	i = 1;
	tmp = param->objet;
	while (tmp)
	{
		tmp->nb = i;
		tmp = tmp->next;
		i++;
	}
}
