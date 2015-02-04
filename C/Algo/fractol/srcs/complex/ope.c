/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 23:48:36 by msarr             #+#    #+#             */
/*   Updated: 2015/01/23 23:48:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx		cplx(double r,double i)
{
	t_cplx	c;

	c.r = x;
	c.i = y;
	return (c);
}
  
/* COPY */
t_real		copy(t_real c)
{
	return complex(c.r , c.i);
}
    
bool 		isZero()
{
	return ( this.x == 0 && this.y == 0 );
}
  
 
  /* CONJUGATE */
  Complex conj()
{
	this.y = - this.y;
	return this;
}
  
  /* OPPOSITE */
  Complex opposite(){
	this.x = - this.x;
	this.y = - this.y;
	
	return this;
  }
  
  /* NORM / ABSOLUTE VALUE */
  float norm(){
	return sqrt( this.x * this.x + this.y * this.y );
  }
  
  /* ABSOLUTE VALUE SQUARED */
  float normSquared(){
	return this.x * this.x + this.y * this.y;
  }
  
  /*
	DISTANCE FROM
	  compute distance from an other complex number
  */
  float distanceFrom( Complex z ){
	return this.sub( z ).norm();
  }
  
  /* ARGUMENT */
  float arg(){
	if( !this.isZero() ){
	  return atan2( this.y , this.x );
	} else {
	  println( "0 has no argument ! " + atan2( this.y , this.x ) );
	  return 0.0;
	}
  }
  
  /*
	CREATE COMPLEX NUMBER AND SET X AND Y FROM POLAR COORDINATES ( NORM , ARG )
	z = Complex.fromPolar( z.norm() , z.arg() )
  */
  static Complex fromPolar( float norm , float arg ){
	return new Complex( norm*cos( arg ) , norm*sin( arg ) );
  }
  
  /* ADD */
  Complex add( Complex z ){
	this.x += z.x;
	this.y += z.y;
	
	return this;
  }
  
  /* SUBTRACT */
  Complex sub( Complex z ){
	this.x -= z.x;
	this.y -= z.y;
	
	return this;
}
/* MULTIPLICATION BY A REAL NUMBER */
  Complex times( float X ){
	this.x *= X;
	this.y *= X;
	
	return this;
  }  
/* MULTIPLICATION BY THE IMAGINARY NUMBER */
  Complex i(){
	float old_x = this.x;
	
	this.x = -this.y;
	this.y = old_x;
	
	return this;
  }
  
  
  /* DIVIDE BY A REAL NUMBER */
  Complex div( float X ){
	if( X != 0 ){
	  this.x /= X;
	  this.y /= X;
	  
	  return this;
	} else {
	  println( "Can't divide by 0 !" );
	  this.x = this.y = 0;
	  return this;
	}
  }
  
  /* MULTIPLY BY COMPLEX */
 
  
  /* INVERT */
  Complex invert(){
	if( !this.isZero() ){
	  // no .copy() because z.normSquared() = z.conj().normSquared()
	  return this.conj().div( this.normSquared() );
	} else {
	  println( "Can't inverse 0 !" );
	  this.x = this.y = 0;
	  return this;
	}
  }
  
  /* DIVIDE */
  Complex div( float X , float Y ){
	if( !Complex.isZero( X , Y ) ){
	  return this.times( X , -Y ).div( X*X + Y*Y );
	} else {
	  println( "Can't divide by 0 !" );
	  this.x = this.y = 0;
	  return this;
	}
  }
  
  Complex div( Complex z ){
	if( !z.isZero() ){
	  return this.times( z.copy().conj() ).div( z.normSquared() );
	} else {
	  println( "Can't divide by 0 !" );
	  z.x = z.y = 0;
	  return this;
	}
  }
  
  /* SQUARED */
  Complex squared(){
	float old_x = this.x;
	
	this.x = old_x*old_x - this.y*this.y;
	this.y = 2*old_x*y;
	
	return this;
  }
  
  /*
	SIMILITUDES
  */
  
  // ROTATION FROM ORIGIN
  Complex rotate( float angle ){
	float cos_ = cos( angle );
	float sin_ = sin( angle );
	
	float x_ = this.x;
	this.x   = x_    *cos_ - this.y*sin_;
	this.y   = this.y*cos_ + x_    *sin_;
	
	return this;
  }
  
  // ROTATION AND EXPANSION FROM ORIGIN
  Complex rotateExpand( float angle , float factor ){
	return this.times( Complex.fromPolar( factor , angle ) );
  }
  
  // ROTATION FROM CENTER
  
  Complex rotateFrom( float angle , Complex a ){
	return this.sub( a ).rotate( angle ).add( a );
  }
  
  Complex rotateFrom( float angle , float x , float y ){
	return this.sub( x , y ).rotate( angle ).add( x , y );
  }
  
  // ROTATION AND EXPANSION FROM CENTER
  Complex rotateExpandFrom( float angle , float factor , Complex a ){
	return this.sub( a ).rotateExpand( angle , factor ).add( a );
  }
   
  Complex rotateExpandFrom( float angle , float factor , float x , float y ){
	return this.sub( x , y ).rotateExpand( angle , factor ).add( x , y );
  }
  
  /*
	NTH POWER
	  compute z to the n, n being an integer
	  uses times() and squared() :
	  "squared exponentiation" => n=2q+r (r=0 or r=1), q=2k+r', etc...
  */
  Complex power( int n ){
	if( !this.isZero() ){
	  if( n > 2 ){
		/* "heavy" computation :
		Complex old = new Complex( this );
		
		for( int i = 1 ; i < n ; i++ ){
		  this.times( old );
		}*/
		
		// "smart" :
		
		Complex old = this.copy();
		
		// n = 2q + k
		int k = n % 2;
		
		// q = (n-k)/2
		this.power( ( n - k )/ 2 ).squared();
		
		if( k == 1 ){
		  this.times( old );
		}
		
		// (z^q)^(2+k) = (z^q)^2 or z*(z^q)^2
		return this;
	  } else if( n == 2 ){
		return this.squared();
	  } else if( n == 1 ){
		return this;
	  } else if( n < 0 ){
		return this.power( -n ).invert();
	  }  else if( n == 0 ){
		return this.set( 1 , 0 );
	  } else {
		return this;
	  }
	} else {
	  // return 0
	  return this;
	}
  }
  
  /*
	XTH POWER
	  compute z to the x, x being real
	  uses norm(), arg() and fromPolar()
	  norm to the x and argument by x :
	  z^x = [r*e^(iA)]^x = (r^x)*e^(i[A*x])
  */
  Complex power( float x ){
	if( !this.isZero() ){
	  return Complex.fromPolar(
		  pow( this.norm() , x )
		, this.arg() * x
	  );
	} else {
	  return this;
	}
  }
  
  
  /*
	ZTH POWER
	  compute the complex to the z, z being complex
  */
  Complex power( Complex z ){
	if( !this.isZero() ){
	  float arg  = this.arg();
	  float norm = this.norm();
	  
	  return Complex.fromPolar(
		  pow( norm , z.x ) / exp( arg * z.y )
		, arg*z.x + log( norm ) * z.y
	  );
	} else {
	  return this;
	}
  }
  
  /*
	EVAL POLYNOMIAL
	  compute P(z)=Sum{ C[i]*z^i }, for all i between 0 and (C.length - 1)
  */
  Complex evalPolynomial( float[][] coefficients ){
	Complex polynomial = new Complex();
	float[] coeff;
	
	int i = coefficients.length - 1;
	while( i >= 0 ){
	  coeff = coefficients[ i ];
	  
	  polynomial.add( coeff[ 0 ] );
	  
	  if( coeff.length == 2 ){
		polynomial.add( 0 , coeff[ 1 ] );
	  }
	  
	  if( i > 0 ){
		polynomial.times( this );
	  }
	  
	  i--;
	}
	
	this.set( polynomial );
	return this;
  }
  
  /*
	EVAL POLYNOMIAL FROM ZEROS
	  compute P(z)=Product{ z - C[i] }, for all i between 0 and (C.length - 1)
	  P(z) = 0 <=> z = C[i] for all i between 0 and (C.length - 1)
  */
  Complex evalPolynomialFromZeros( float[][] coefficients ){
	Complex polynomial = new Complex( 1 , 0 );
	int     length;
	
	int i = 0;
	while( i < coefficients.length ){
	  
	  length = coefficients[ i ].length;
	  
	  if( length == 3 ){
		polynomial.times( this.copy().sub( coefficients[ i ][ 0 ] , coefficients[ i ][ 1 ] ).power( coefficients[ i ][ 2 ] ) );
	  } else if( length == 2 ){
		polynomial.times( this.copy().sub( coefficients[ i ][ 0 ] , coefficients[ i ][ 1 ] ) );
	  } else {
		polynomial.times( this.copy().sub( coefficients[ i ][ 0 ] ) );
	  }
	  
	  
	  i++;
	}
	
	//this.set( polynomial );
	//return this;
	return polynomial;
  }
  
  /*
	SQUARE ROOT
	  complex's first square root
  */
  Complex Sqrt(){
	return Complex.fromPolar( sqrt( this.norm() ) , this.arg()/2.0 );
  }
  
  
  /* EXP */
  static Complex Exp( Complex z ){
	return Complex.fromPolar( exp( z.x ) , z.y );
  }
  
  /*
	LOG
	  complex's log on the principal branch
  */
  static Complex Log( Complex z ){
	if( !z.isZero() ){
	  return new Complex( log( z.norm() ) , z.arg() );
	} else {
	  return new Complex( 0 , 0 );
	}
  }
  
  /*
	CICLE  / UNIT / NORMALIZE
	  put the complex on the unit circle (keeping argument)
  */
  Complex circle(){
	if( !this.isZero() ){
	  return this.div( this.norm() );
	} else {
	  println( "Can't normalize 0 !" );
	  this.x = this.y = 0;
	  return this;
	}
  }
  
  /*
	MANDELBROT
	  compute a polynomial from the complex and a finite number of iteration
	  there's no escape (norm > 2 => we stop)
	  the (original) mandelbrot set would be power = 2
  */
  Complex mandelbrot( int iteration , int power ){
	if( iteration > 0 ){
	  
	  int i = 0;
	  Complex old_z = this.copy();
	  
	  while( i < iteration ){
		this.power( power ).add( old_z );
		i++;
	  }
	  
	  return this;
	} else {
	  return this;
	}
  }
  
  /*
	MANDELBROT SEED (JULIA)
	  compute a polynomial from the complex and a finite number of iteration
	  there's no escape (norm > 2 => we stop)
	  the (original) julia set would be power = 2
  */
  Complex mandelbrot( int iteration , int power , Complex seed ){
	if( iteration > 0 ){
	  
	  int i = 0;
	  while( i < iteration ){
		this.power( power ).add( seed );
		i++;
	  }
	  
	  return this;
	} else {
	  return this;
	}
  }
  
  /* COMPLEX TRIGONOMETRIC FUNCTIONS */
  
  /* COS */
  static Complex Cos( Complex z ){
	float a = exp( z.y );
	float b = 1.0/a;
	
	a = a/2.0;
	b = b/2.0;
	
	return new Complex(
		 cos( z.x ) * ( a + b )
	  , -sin( z.x ) * ( a - b )
	);
	// slower
	/*return new Complex(
		 cos( z.x ) * Complex.CosH( z.y )
	  , -sin( z.x ) * Complex.SinH( z.y ) 
	);*/
  }
  
  /* SIN */
  static Complex Sin( Complex z ){
	float a = exp( z.y );
	float b = 1.0/a;
	
	a = a/2.0;
	b = b/2.0;
	
	return new Complex(
		sin( z.x ) * ( a + b )
	  , cos( z.x ) * ( a - b )
	);
	// slower
	/*return new Complex(
		sin( z.x ) * Complex.CosH( z.y )
	  , cos( z.x ) * Complex.SinH( z.y ) 
	);*/
  }