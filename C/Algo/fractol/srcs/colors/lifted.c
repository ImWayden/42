/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:14:19 by msarr             #+#    #+#             */
/*   Updated: 2015/02/04 13:14:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



vec2 cMul2(in vec2 a, in vec2 b) {
	return vec2( a.x*b.x -  a.y*b.y,a.x*b.y + a.y * b.x);
}

float sqr(float a) { return a; }

vec2 formula(vec2 z) {
	vec2 real = vec2(1.,0.); vec2 imag = vec2(0.,1.);
	vec2 z2 =  cMul(cSqr(z+real),  z-real);
	vec2 z3 =  cMul(z+imag, cSqr(z-imag));
	z = cDiv(z2,z3);
	return z;
}

vec2 toPhiTheta(vec2 z) {
	float r = length(z);
	float phi = 2.*atan(1./r);
	float theta = atan(z.y,z.x);
	return vec2(phi,theta);
}
uniform float delta; slider[0.0,0.001,1.0]

// Convert to
uniform float GridWidth; slider[-10,-1,10]
vec3 baseColor(vec3 pos, vec3 n) {
	vec2 z = pos.xy;
	// Restrict
	//if (abs(z).x>3.0) return vec3(0.);
	//if (abs(z).y>3.0) return vec3(0.);
	
	z = formula(z);
	// Inverse map complex plane to 2-sphere
	// using spherical coordinates:
	float r = length(z);
	float phi = 2.*atan(1./r);
	float theta = atan(z.y,z.x);
	
	
	vec2 zdxpt = toPhiTheta(formula(z+vec2(delta,0.)));
	vec2 zdypt = toPhiTheta(formula(z+vec2(0.,delta)));
	float zdp = sqrt( sqr(zdxpt.x-phi) + sqr(zdypt.x-phi))/delta;
	float zdt = sqrt( sqr(zdxpt.y-theta) + sqr(zdypt.y-theta))/delta;
	//	r = zdp;
	
	float b0 = fract(2.0*log(r)/log(2.)); // fractional brightness
	float b1 = fract(log(r)/log(2.));        // ... for every second band
	
	float m = mod(theta , PI/6.); // twelve white rays.
	float p10 =pow(10.,GridWidth); // grid width
	
	// adjust brightness
	float b = (b0+1.0)/2.0;
	if (b1<0.5) b = 1.0;
	// saturation and value
	float s = 1.0;
	float val = 1.0;

	if (phi<PI/2.) s = sin(phi); else val = sin(phi);
	s=pow(s,0.5);
	val=pow(val,0.5);
	s = 1.0; val = 1.0;
	// convert
	vec3 v = HSVtoRGB(vec3(theta,s,val))*b;
	
	// blend in grid
	if (m<p10) v =mix(vec3(1.0),v, m/p10);
	if (m>PI/6.-p10) v =mix(v,vec3(1.0),( m-(PI/6.-p10) )/p10);
	
	if (b0<p10) v =mix(vec3(0.0),v, b0/p10);
	if (b0>1.-p10) v =mix(v,vec3(0.0),( b0-(1.-p10) )/p10);
	
	return v;
}

float Sigmoid(float x) {
	return (1.0/ (1.0+exp(-x/10.0)))-0.5;
}
float T(float x) {
	return 2.0* Sigmoid(abs(x+1./x));
}