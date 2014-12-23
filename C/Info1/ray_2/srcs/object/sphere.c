/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 22:34:01 by msarr             #+#    #+#             */
/*   Updated: 2014/12/20 18:34:06 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"


t_vect			normal_sphere(t_scene *s, t_vect p)
{
   return (sub(p, s->pos));
}

int				hitSphere(t_ray *ray, t_scene *sphere, double *dist)
{
  double    a;
  double    b;
  double    c;

  t_vect    ro_sc;
  double    disc;
  double    distSqrt;
  double    t0;
  double    t1;
  double    swap;

  a = dot(ray->dir, ray->dir);
  ro_sc = sub(ray->orig, sphere->pos);
  b = 2.0 * dot(ray->dir, ro_sc);
  c = dot(ro_sc, ro_sc) - SQUARE(sphere->size);
  disc = SQUARE(b) - 4 * a * c;
  if (disc < 0)
    return 0;
  distSqrt = sqrt(disc);
  t0 = (-b - distSqrt);
  t1 = (-b + distSqrt);
  if (t0 > t1)
  {
    swap = t0;
    t0 = t1;
    t1 = swap;
  }
  if (t1 < 0)
    return 0;
  else if(t0 < 0)
    *dist = t1;
  else
    *dist = t0;
  return 1;
/*t_vect d = sub(sphere->pos, ray->orig); 
   float B = dot(ray->dir, d);
   float D = B*B - dot(d, d) + SQUARE(sphere->size); 
   if (D < 0.0f) 
     return 0; 
   float t0 = B - sqrtf(D); 
   float t1 = B + sqrtf(D);
   int retvalue = 0;  
   if ((t0 > 0.1f) && (t0 < *dist)) 
   {
     *dist = t0;
     retvalue = 1; 
   } 
   if ((t1 > 0.1f) && (t1 < *dist)) 
   {
     *dist = t1; 
     retvalue = 1; 
   }
  return retvalue;*/
}
