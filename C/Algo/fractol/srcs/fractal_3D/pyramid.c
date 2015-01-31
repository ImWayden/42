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

void		plot3d(t_env *env, t_coord c, int i)
{
	double	x;
	double	y;

	x = (0.71 * (c.x - c.y) + 4) * 75.0;
	y = (-0.82 * c.z + 0.41 * (c.x + c.y) + 4) * 75.0;
	printf("hhh %lf - %lf\n", x, y);
	if (x >= 0 && y >= 0)
	plotpixel(env, (int)x , (int)y, env->colormap[i].rgb);
}

void		drawp(t_env *env, t_coord *t)
{
	double	k;
	double	n;
	t_coord	v;
	int		i;

	v = newc(0.0,0.0,0.0);
	n = 2;
	env->max_i = 400000;
	while (n < env->max_i)
	{
		k = RANDR(-1, 1);
		i = 0;
		while(i < 3)
		{
			if (k > ((double)i - 1.0) / 6.0 && k < (double) i / 6.0)
			{
	//v = newc(0.0,0.0,0.0);

				v = mult(add(v, t[i]), 1.0/2.0);
				plot3d(env, v, i);
			}
			i++;
		}
		n++;
	}
}

int			pyramid(t_env *env)
{
	t_coord	t[8];

	t[2] = newc(0.0, 0.0, 2.0);

	t[0] = newc(-1.0, 1.0, 0.0);
	t[1] = newc(-1.0, -1.0, 0.0);
	drawp(env, t);
	
	t[0] = newc(-1.0, -1.0, 0.0);
	t[1] = newc(1.0, -1.0, 0.0);
	drawp(env, t);
	
	t[0] = newc(1.0, 1.0, 0.0);
	t[1] = newc(1.0, -1.0, 0.0);
	drawp(env, t);
	

	t[0] = newc(-1.0, 1.0, 0.0);
	t[1] = newc(1.0, 1.0, 0.0);
	drawp(env, t);
	
	return (0);
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

