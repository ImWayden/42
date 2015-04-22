/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:16:31 by msarr             #+#    #+#             */
/*   Updated: 2015/04/20 22:16:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void Sierpinski(pair A, real s, int q, bool top=true)
{
  pair B=A-(1,sqrt(2))*s/2;
  pair C=B+s;
  if(top) draw(A--B--C--cycle);
  draw((A+B)/2--(B+C)/2--(A+C)/2--cycle);
  if(q > 0) {
    Sierpinski(A,s/2,q-1,false);
    Sierpinski((A+B)/2,s/2,q-1,false);
    Sierpinski((A+C)/2,s/2,q-1,false);
  }
}

Sierpinski((0,1),1,5);