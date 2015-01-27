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