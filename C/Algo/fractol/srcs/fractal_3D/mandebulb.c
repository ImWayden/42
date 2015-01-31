/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandebulb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 08:05:01 by msarr             #+#    #+#             */
/*   Updated: 2015/01/23 08:05:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			pyramid(t_env *env)
{
	t_coord	t[6];
	t_coord	v;
	t_point	*list = NULL;
	int		i;
	int		n;
	double	k;

	t[1] = newc(0.0, 0.0, 0.0);
	t[2] = newc(0.0, 1.0/2.0, 0.0);
	t[3] = newc(1.0/2.0, 0.0, 0.0);
	t[4] = newc(1.0/2.0, 1.0/2.0, 0.0);
	t[5] = newc(1.0/4.0, 1.0/4.0, 1.0/2.0);
	printf("%lf\n", t[5].x);
	v = newc(0.0,0.0,0.0);
	n = 2;
			int j = 0;
	env->max_i = 40000;
	while (n < env->max_i)
	{
		k = RANDR(0, 1);
		i = 1;
		while(i <= 5)
		{
			if (k > ((double)i-1.0)/5.0 && k < (double)i/5.0)
			{
				v = add(mult(v, 1.0/2.0), t[i]);
				list = addlist(env, list, v);
				printf("hhh %lf - %lf\n", list->c.x, list->c.y);
				j++;
			}
			i++;
		}
		n++;
	}
	printf("%lf %lf\n", env->x_min, env->y_min);
	while (list)
	{
		plotpixel(env, (int)list->c.x , (int)list->c.y, LightGrey);
		list = list->next;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	ft_putendl("ok");
	return (0);
}



float DE(vec3 pos) {
	vec3 z = pos;
	float dr = 1.0;
	float r = 0.0;
	for (int i = 0; i < Iterations ; i++) {
		r = length(z);
		if (r>Bailout) break;
		
		// convert to polar coordinates
		float theta = acos(z.z/r);
		float phi = atan(z.y,z.x);
		dr =  pow( r, Power-1.0)*Power*dr + 1.0;
		
		// scale and rotate the point
		float zr = pow( r,Power);
		theta = theta*Power;
		phi = phi*Power;
		
		// convert back to cartesian coordinates
		z = zr*vec3(sin(theta)*cos(phi), sin(phi)*sin(theta), cos(theta));
		z+=pos;
	}
	return 0.5*log(r)*r/dr;
}

float theta = asin( z.z/r );
float phi = atan( z.y,z.x );
... 
z = zr*vec3( cos(theta)*cos(phi), cos(theta)*sin(phi), sin(theta) );
///////////////////////////
int last = 0;
float escapeLength(in vec3 pos)
{
	vec3 z = pos;
	for( int i=1; i&lt;Iterations; i++ )
	{
		z = BulbPower(z, Power) + pos;
		float r2 = dot(z,z);
		if ((r2 > Bailout && last==0) || (i==last))
		{
			last = i;
			return length(z);
		}
	}	
	return length(z);
}

float DE(vec3 p) {
	last = 0;
	float r = escapeLength(p);
	if (r*r&lt;Bailout) return 0.0;
	gradient = (vec3(escapeLength(p+xDir*EPS), escapeLength(p+yDir*EPS), escapeLength(p+zDir*EPS))-r)/EPS;
	return 0.5*r*log(r)/length(gradient);
}

////////////


float potential(in vec3 pos)
{
	vec3 z = pos;
	for(int i=1; i&lt;Iterations; i++ )
	{
 		z = BulbPower(z, Power) + pos;
		if (dot(z,z) > Bailout) return log(length(z))/pow(Power,float(i));
	}	
	return 0.0;	
}

float DE(vec3 p) {
	float pot = potential(p);
	if (pot==0.0) return 0.0;
	gradient = (vec3(potential(p+xDir*EPS), potential(p+yDir*EPS), potential(p+zDir*EPS))-pot)/EPS;
	return (0.5/exp(pot))*sinh(pot)/length(gradient);
}