/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 01:29:57 by msarr             #+#    #+#             */
/*   Updated: 2014/11/29 12:27:55 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void PlotPixel(t_env *env, int x, int y, short r, short g, short b)
{
	//first thing is to make sure the

	//pixel is within range of the screen
	if(x<0 || x> SCREEN_W)
		return;
	if(y<0 || y> SCREEN_H)
		return;
	unsigned int p = x + y* SCREEN_W;

	//see if the pixel is the closest to the camera
	//make sure the color is in range
	if(r>255) r=255;
	if(g>255) g=255;
	if(b>255) b=255;
	if(r<0) r=0;
	if(g<0) g=0;
	if(b<0) b=0;
	//"plot" the pixel
	p*=4;
	env->data[p] = r;
	env->data[p + 1] = g;
	env->data[p + 2] = b;
}

int raytracer(t_env *env)
{
	float cop = -100.0f;
	float x,y,q;
	unsigned int r,g,b;
	float lr,lg,lb;
	int ret=0, j;
	t_vect *P, *a;
	t_sphere	sphere;
	float ambient = 0.5;
	float theta=0, phi=0;
	

	theta+=0.1;
	phi+=0.05;
	set_pos(&env->light.vect , sin(theta)*128+128,128+cos(phi)*128,cos(theta)*128);
	set_pos(&env->sphere2.vect, env->light.vect.x,env->light.vect.y,env->light.vect.z);
	for(y=0;y<SCREEN_H;y++)
	{
		for(x=0;x<SCREEN_W;x++)
		{
			PlotPixel(env, x,y,64,128,255);
			for(j=0;j<2;j++)
			{
				if (j == 1)
					sphere = env->sphere1;
				else
					sphere = env->sphere2;
				P = ray_sphere(&sphere, 128.0f,128.0f,cop,x,y,0.0,&ret);
				if(ret>0)
				{
					//apply lighting
					lr=0;
					lg=0;
					lb=0;
					a = normal_at(&sphere, P->x,P->y,P->z);
					q = getIntensityAtAngle(env->light, P->x,P->y,P->z,*a);
					lr += (float)env->light.color.x*q;
					lg += (float)env->light.color.y*q;
					lb += (float)env->light.color.z*q;
					r=(short)((lr/255.0f+ambient)* sphere.color.x);
					g=(size_t)((lg/255.0f+ambient)* sphere.color.y);
					b=(short)((lb/255.0f+ambient)* sphere.color.z);
					//z = sqrt((cop-P->z)*(cop-P->z)+(128-P->x)*(128-P->x)+(128-P->y)*(128-P->y));
					PlotPixel(env, x,y,r,g,b);
				}
			}
		}
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (1);
}
