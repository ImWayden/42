/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:22:43 by msarr             #+#    #+#             */
/*   Updated: 2015/05/03 15:22:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <GLFW/glfw3.h>
#include "arkanoid.h"


/*****************************************************************************
 * Truncate a degree.
 *****************************************************************************/
GLfloat TruncateDeg( GLfloat deg )
{
   if ( deg >= 360.f )
      return (deg - 360.f);
   else
      return deg;
}

/*****************************************************************************
 * Convert a degree (360-based) into a radian.
 * 360' = 2 * PI
 *****************************************************************************/
double deg2rad( double deg )
{
   return deg / 360 * (2 * M_PI);
}

/*****************************************************************************
 * 360' sin().
 *****************************************************************************/
double sin_deg( double deg )
{
   return sin( deg2rad( deg ) );
}

/*****************************************************************************
 * 360' cos().
 *****************************************************************************/
double cos_deg( double deg )
{
   return cos( deg2rad( deg ) );
}

/*****************************************************************************
 * Compute a cross product (for a normal vector).
 *
 * c = a x b
 *****************************************************************************/
void CrossProduct( vertex_t a, vertex_t b, vertex_t c, vertex_t *n )
{
   GLfloat u1, u2, u3;
   GLfloat v1, v2, v3;

   u1 = b.x - a.x;
   u2 = b.y - a.y;
   u3 = b.y - a.z;

   v1 = c.x - a.x;
   v2 = c.y - a.y;
   v3 = c.z - a.z;

   n->x = u2 * v3 - v2 * v3;
   n->y = u3 * v1 - v3 * u1;
   n->z = u1 * v2 - v1 * u2;
}


/*****************************************************************************
 * Calculate the angle to be passed to gluPerspective() so that a scene
 * is visible.  This function originates from the OpenGL Red Book.
 *
 * Parms   : size
 *           The size of the segment when the angle is intersected at "dist"
 *           (ie at the outermost edge of the angle of vision).
 *
 *           dist
 *           Distance from viewpoint to scene.
 *****************************************************************************/

GLfloat PerspectiveAngle( GLfloat size,GLfloat dist )
{
   GLfloat radTheta, degTheta;

   radTheta = 2.f * (GLfloat) atan2( size / 2.f, dist );
   degTheta = (180.f * radTheta) / (GLfloat) M_PI;
   return degTheta;
}