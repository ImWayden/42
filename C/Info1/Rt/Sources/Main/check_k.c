/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_k.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:52:27 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:04:42 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

t_k		*check_k(t_k *k2, t_k *k)
{
	if ((k2 && k && k2->k >= 0.0 && k->k <= k2->k && k->k >= 0.0) ||
		(k2 && k && k2->k < 0.0 && k->k >= 0.0))
	{
		free(k2);
		return (k);
	}
	return (k2);
}

void	copy_obj_to_k(t_k *k2, t_objet *tmp)
{
	k2->type = tmp->type;
	k2->color.red = tmp->color.red;
	k2->color.green = tmp->color.green;
	k2->color.blue = tmp->color.blue;
	k2->brill = tmp->brill;
	k2->nb = tmp->nb;
	k2->ind = tmp->middle;
}

void	init_k2(t_k *k2, t_objet *tmp, t_utils utils)
{
	trans_inv(&utils, tmp, 0);
	obj_rot(&utils, tmp, -1, 1);
	if (tmp->type == PLAN)
		k2->k = inter_plan(utils, tmp);
	else if (tmp->type == SPHERE)
		k2->k = inter_sphere(utils, tmp);
	else if (tmp->type == CONE)
		k2->k = inter_cone(utils, tmp);
	else if (tmp->type == CYLINDRE)
		k2->k = inter_cylindre(utils, tmp);
	else if (tmp->type == PARABOLOIDE)
		k2->k = inter_paraboloide(utils, tmp);
	else if (tmp->type == HYPERBOLOIDE)
		k2->k = inter_hyperboloide(utils, tmp);
	else
		k2->k = -1.0;
	obj_rot(&utils, tmp, 1, 1);
	trans_nor(&utils, tmp, 0);
	copy_obj_to_k(k2, tmp);
}

t_k		*search_k(t_objet *tmp, t_utils utils, t_k *k, t_param *param)
{
	t_k	*k2;

	k2 = malloc(sizeof(*k2));
	if (!k2)
		exit(0);
	init_k2(k2, tmp, utils);
	if (k2->k == -1.0)
	{
		k2->color.red = 0.0;
		k2->color.green = 0.0;
		k2->color.blue = 0.0;
	}
	param = param;
	if (k2->k >= 0.00)
	{
		k2 = luminosite(param->spot, k2, tmp, &utils);
		k2 = shadow(param, tmp, k2, &utils);
	}
	k = check_k(k2, k);
	return (k);
}
