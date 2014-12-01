/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:18:28 by msarr             #+#    #+#             */
/*   Updated: 2014/11/29 11:45:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

float		getIntensityAt(t_light light, float px,float py,float pz)
{
	float	dist;

	dist = sqrt((light.vect.x-px)*(light.vect.x-px) + (light.vect.y-py)*(light.vect.y-py) + (light.vect.z-pz)*(light.vect.z-pz) );
	if(dist>=1.0)
			return light.i/dist;
	return light.i;
}

float		getIntensityAtAngle(t_light light, float px, float py, float pz, t_vect normal)
{
	float	intensity;
	float	angle;
	float	dist;
	t_vect	a;

	dist = sqrt((light.vect.x - px) * (light.vect.x - px) +	(light.vect.y - py) * (light.vect.y - py) + (light.vect.z - pz) * (light.vect.z - pz));
	if(dist>=1.0)
		intensity = light.i/dist;
	else
		intensity = light.i;
	a.x = light.vect.x-px;
	a.y = light.vect.y-py;
	a.z = light.vect.z-pz;
	a.d = 1.0f/sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	a.x*=a.d;
	a.y*=a.d;
	a.z*=a.d;
	angle = (a.x*normal.x + a.y*normal.y + a.z*normal.z);
	if(angle <= 0)
		return 0;
	return intensity * angle;
}
