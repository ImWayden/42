/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 23:16:13 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 18:12:49 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_scene			*new_scene()
{
	t_scene		*new;

	if ((new = (t_scene *)malloc(sizeof(t_scene))))
		new->next = NULL;
	return (new);
}

t_light			*new_light()
{
	t_light		*new;

	if ((new = (t_light *)malloc(sizeof(t_light))))
		new->next = NULL;
	return (new);
}

t_lex			*get_obj(t_env *env, t_lex *lex)
{
	t_scene	*s;
	t_light	*l;

	
	while (lex)
	{
		if (!ft_strcmp(lex->str, "<SPHERE>"))
		{
			s = new_scene();
			s->next = env->scene;
			env->scene = s;
			lex = get_sphere(s, lex->next);
		}
		else if (!ft_strcmp(lex->str, "<PLAN>"))
		{
			s = new_scene();
			s->next = env->scene;
			env->scene = s;
			lex = get_plan(s, lex->next);
		}
		else if (!ft_strcmp(lex->str, "<SPOT>"))
		{
			l = new_light();
			l->next = env->light;
			env->light = l;
			lex = get_light(l, lex->next);
		}
		else
			break ;
	}
	return (lex);
}