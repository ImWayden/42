/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:16:35 by msarr             #+#    #+#             */
/*   Updated: 2015/01/28 19:16:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*iterations=40000*/
t_coord		newc(double x, double y, double z)
{
	t_coord	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_coord		add(t_coord vect, t_coord vect1)
{
	t_coord	v;

	v.x = vect.x + vect1.x;
	v.y = vect.y + vect1.y;
	v.z = vect.z + vect1.z;
	return (v);
}

t_coord		mult(t_coord vect, double d)
{
	t_coord	v;

	v.x = vect.x * d;
	v.y = vect.y * d;
	v.z = vect.z * d;
	return (v);
}

t_point		*addlist(t_env *env, t_point *p, t_coord c)
{
	static int i = 0;
	t_point	*tmp;

	if (!i)
	{
		env->x_min = 0;
		env->y_min = 0;
	}
	tmp = malloc(sizeof(t_point));
	tmp->c.x = (0.71 * (c.x - c.y) + 1) * SCREEN_H / 2;
	tmp->c.y = (-0.82 * c.z + 0.41 * (c.x + c.y) + 1) * SCREEN_H / 2;
	tmp->next = p;
	return (tmp);
}

/*

  ;;;creates a pyramid
    (define (pyramid c1 c2 c3 ctop)
      (polygon c1 c2 ctop)
      (polygon c2 c3 ctop)
      (polygon c3 c1 ctop)
      (polygon c1 c2 c3))

    ;;;recursively creates pyramids in order to create sierpinski's triangles in 3D
    (define (sierpinski c1 c2 c3 ctop depth)
      (if (> depth 0)
        (begin
          (pyramid c1 c2 c3 ctop)
          (sierpinski c1 (mid c1 c2) (mid c1 c3) (mid c1 ctop) (- depth 1))
          (sierpinski c2 (mid c2 c3) (mid c2 c1) (mid c2 ctop) (- depth 1))
          (sierpinski c3 (mid c3 c1) (mid c3 c2) (mid c3 ctop) (- depth 1))
          (sierpinski (mid c1 ctop) (mid c2 ctop) (mid c3 ctop) ctop (- depth 1)))
        (pyramid c1 c2 c3 ctop)))

    ;;;initiating the pyramid
    (sierpinski (list -50 -20 -50) (list 50 -20 -40) (list 10 0 -85) (list 5 40 -65) 4)

*/

