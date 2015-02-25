/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funt1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 19:05:52 by msarr             #+#    #+#             */
/*   Updated: 2015/01/27 19:05:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#define FLAME_R2 double r2 = *x*(*x) + *y*(*y);
#define FLAME_THETA double t = atan((*x)/(*y))
#define FLAME_PHY double p = atan((*y)/(*x))
#define FLAME_TR double tr = t*r
#define FLAME_OLDX double oldx = *x
#define FLAME_RSYM(x_or_y) if(rand()%2){*(x_or_y) *= -1;}
#define FLAME_SYMY(f1, f2) if(*y < 0)\
{\
    *x = (f1);\
    *y = (f2);\
}\
else\
{\
    *x = -(f1);\
    *y = -(f2);\
}
#define FLAME_SYMX(f1, f2) if(*x < 0)\
{\
    *x = (f1);\
    *y = (f2);\
}\
else\
{\
    *x = -(f1);\
    *y = -(f2);\
}

void flame_waves(double* x, double* y) // Waves (Variation 15)
{
    FLAME_OLDX;
    *x = *x + xy*sin(  *y/xc/xc);
    *y = *y + yy*sin(oldx/yc/yc);
}

void flame_fisheye(double* x, double* y) // Fisheye (Variation 16)
{
    FLAME_R; FLAME_OLDX;
    const double c = 2/(r + 1);
    *x = c*(*y);
    *y = c*oldx;
}

void flame_popcorn(double* x, double* y) // Popcorn (Variation 17)
{
    FLAME_OLDX;
    *x = *x + yy*sin(tan(3*(*y)));
    *y = *y + yc*sin(tan(3*oldx));
}

void flame_exponential(double* x, double* y) // Exponential (Variation 18)
{
    const double c = exp(*x - 1.0);
    *x = c*cos(M_PI*(*y));
    *y = c*sin(M_PI*(*y));
}

void flame_power(double* x, double* y) // Power (Variation 19)
{
    FLAME_THETA; FLAME_R;
    const double c = pow(r, sin(t));
    *x = c*cos(t);
    *y = c*sin(t);
    // à ce moment : x est entre 0 et 1
    //*x = 1 - *x; less scary :o
    //*y *= -1;
    FLAME_RSYM(x); // on veut deux yeux
    /* *y -= 0.23;
    *y /= 1.8;
    *x /= 1.8;*/
}

void flame_cosine(double* x, double* y) // Cosine (Variation 20)
{
    FLAME_OLDX;
    *x =  cos(M_PI*(*x))*cosh(*y);
    *y = -sin(M_PI*oldx)*sinh(*y);
    //*x -= 0.3;
}

void flame_rings(double* x, double* y) // Rings (Variation 21)
{
    FLAME_R; FLAME_THETA;
    double c = fmod(r + xc*xc, 2*xc*xc) - xc*xc + r*(1 - xc*xc);
    //*x = c*cos(t);
    //*y = c*sin(t);
    FLAME_SYMY(c*cos(t), c*sin(t));
}

void flame_fan(double* x, double* y) // Fan (Variation 22)
{
    FLAME_THETA; FLAME_R;
    const double tc = M_PI*xc*xc;
    if( fmod(t + yc, tc) > tc/2)
    {
        //*x = r*cos(t - tc/2);
        //*y = r*sin(t - tc/2);
        FLAME_SYMY(r*cos(t - tc/2), r*sin(t - tc/2));
    }
    else
    {
        //*x = r*cos(t + tc/2);
        //*y = r*sin(t + tc/2);
        FLAME_SYMY(r*cos(t + tc/2), r*sin(t + tc/2));
    }
}

void flame_blob(double* x, double* y) // Blob (Variation 23)
{
    FLAME_THETA; FLAME_R;
    double high = 0.9, low = 0.1, waves = 5;
    double c = r*(low+(high-low)/2.0*(sin(waves*t)+1));
    *x = c*cos(t);
    *y = c*sin(t);
    FLAME_RSYM(x);
}

double pdj1 = 1.2;
double pdj2 = 2.0;
double pdj3 = 1.5;
double pdj4 = 2;

void flame_pdj(double* x, double* y) // PDJ (Variation 24)
{
    FLAME_OLDX;
    *x = sin(pdj1*(*y)) - cos(pdj2*(*x));
    *y = sin(pdj3*oldx) - cos(pdj4*(*y));
    //*x /= 2;
    //*y /= 2;
}

double fan2x = 0.8;
double fan2y = -0.33;

void flame_fan2(double* x, double* y) // Fan2 (Variation 25)
{
    FLAME_THETA; FLAME_R;
    double p1 = M_PI*fan2x*fan2x;
    double p2 = fan2y;
    if(t+p2-p1*(int)(2*t*p2/p1) > p1/2)
    {
        //*x = r*sin(t - p1/2);
        //*y = r*cos(t - p1/2);
        FLAME_SYMX(r*sin(t - p1/2), r*cos(t - p1/2));
        //FLAME_SYMY(r*sin(t - p1/2), r*cos(t - p1/2));
    }
    else
    {
        //*x = r*sin(t + p1/2);
        //*y = r*cos(t + p1/2);
        FLAME_SYMX(r*sin(t + p1/2), r*cos(t + p1/2));
        //FLAME_SYMY(r*sin(t + p1/2), r*cos(t + p1/2));
    }
    if(rand()%2)
    {
        *x *= -1;
        *y *= -1;
    }
}

const double rings2val = 0.4;

void flame_rings2(double* x, double* y) // Rings2 (Variation 26)
{
    FLAME_THETA; FLAME_R;
    double p = rings2val*rings2val;
    double t1 = r - 2*p*(double)(int)((r+p)/2/p)+r*(1-p);
    //*x = t1*sin(t);
    //*y = t1*cos(t);
    FLAME_SYMY(t1*sin(t), t1*cos(t));
    //*x /= 1.3;
    //*y /= 1.3;
}

void flame_eyefish(double* x, double* y) // Eyefish (Variation 27)
{
    FLAME_R;
    double c = 2/(r+1);
    *x *= c;
    *y *= c;
    //*x /= 1.33;
    //*y /= 1.33;
}

void flame_bubble(double* x, double* y) // Bubble (Variation 28)
{
    FLAME_R;
    double c = 4/(r*r+4);
    *x *= c;
    *y *= c;
}

void flame_cylinder(double* x, double* y) // Cylinder (Variation 29)
{
    *x = sin(*x);
    //*x /= 2.0;
}

void flame_perspective(double* x, double* y) // Perspective (Variation 30)
{
    double p1 = M_PI/180*70;
    double p2 = 10;
    double c = p2/(p2-*y*p1);
    *x *= c;
    *y *= c*cos(p1);
}

void flame_noise(double* x, double* y) // Noise (Variation 31)
{
    double k1 = FLAME_KSY;
    double k2 = FLAME_KSY;
    *x *= k1*cos(2*M_PI*k2);
    *y *= k1*sin(2*M_PI*k2);
}

void flame_julian(double* x, double* y) // JuliaN (Variation 32)
{
    FLAME_PHY; FLAME_R;
    // careful to this ratio: p1/p2
    double p1, p2; // power; distance
    p1 = 7; p2 = 7.5;
    //p1 = 800; p2 = 1000;
    //p1 = 400; p2 = 10;
    //p1 = 0.2; p2 = 0.2; // low float changes everything
    //p1 = 1.0/4; p2 = p1/1.618;
    double p3 = (int)((p1<0?-p1:p1)*FLAME_KSY);
    double t1 = (p + 2*M_PI*p3)/p1;
    double c = pow(r, p2/p1);
    *x = c*cos(t1);
    *y = c*sin(t1);
}

void flame_juliascope(double* x, double* y) // JuliaScope (Variation 33)
{
    FLAME_PHY; FLAME_R;
    double lambda = 2.0;
    double p1, p2; // power; distance
    // careful to this ratio: p1/p2
    p1 = 7; p2 = 7.5;
    //p1 = 800; p2 = 1000;
    //p1 = 400; p2 = 10;
    //p1 = 0.2; p2 = 0.2; // low float changes everything
    //p1 = 1.0/4; p2 = p1/1.618;
    double p3 = (int)((p1<0?-p1:p1)*FLAME_KSY);
    double t1 = (lambda*p + 2*M_PI*p3)/p1;
    double c = pow(r, p2/p1);
    *x = c*cos(t1);
    *y = c*sin(t1);
}

void flame_blur(double* x, double* y) // Blur (Variation 34)
{
    double k1 = FLAME_KSY;
    double k2 = FLAME_KSY;
    *x = k1*cos(2*M_PI*k2);
    *y = k1*sin(2*M_PI*k2);
}

void flame_gaussian(double* x, double* y) // Gaussian (Variation 35)
{
    /* Summing 4 random numbers and subtracting 2 is an attempt at approximating
a Gaussian distribution. */
    double c = -2;
    int i;
    for(i = 0; i < 4; i++)
        c += FLAME_KSY;
    double k5 = FLAME_KSY;
    *x = c*cos(2*M_PI*k5);
    *y = c*sin(2*M_PI*k5);
}

void flame_radialblur(double* x, double* y) // RadialBlur (Variation 36)
{
    FLAME_R; FLAME_PHY;
    double p1 = /* angle = ( */ M_PI/3 /* ) */ *M_PI/2;
    double t1 = -2;
    int i;
    for(i = 0; i < 4; i++)
        t1 += FLAME_KSY;
    // to do: t1 *= radialblur
    double t2 = p + t1*sin(p1);
    double t3 = t1*cos(p1) - 1;
    *x = r*cos(t2) + t3*(*x);
    *y = r*sin(t2) + t3*(*y);
    // to do: (x, y) /= radialblur
}

void flame_pie(double* x, double* y) // Pie (Variation 37)
{
    double p1, p2, p3; // slices; rotation; thickness
    p1 = 7; // nombre de parts
    p2 = M_PI/180*20; // 20° de rotation autours de l'axe Z
    p3 = 0.77; // ratio plein/vide
    double k1 = FLAME_KSY;
    double k2 = FLAME_KSY;
    double k3 = FLAME_KSY;
    double t1 = (int)(k1*p1+0.5);
    double t2 = p2 + 2*M_PI/p1*(t1 + k2*p3);
    *x = k3*cos(t2);
    *y = k3*sin(t2);
}

void flame_ngon(double* x, double* y) // Ngon (Variation 38)
{
    FLAME_PHY; FLAME_R;
    double p1, p2, p3, p4; // power, 2pi/sides, corners, circle
    p1 = 3;
    p2 = 1;
    p3 = 3;
    p4 = 0.2;
    p2 = 2*M_PI/p2;
    double t3 = p - p2*(int)(p/p2); // devrait être |_p/p2_|
    double t4 = t3;
    if(t3 <= p2/2)
        t4 -= p2;
    double k = (p3*(1/cos(t4) - 1) + p4)/pow(r, p1);
    *x *= k;
    *y *= k;
}

void flame_curl(double* x, double* y) // Curl (Variation 39)
{
    FLAME_OLDX;
    double p1 = 0.8;
    double p2 = 0.5;
    double t1 = 1 + p1*(*x) + p2*(*x*(*x)-*y*(*y));
    double t2 = p1*(*y) + 2*p2*(*x)*(*y);
    double c = 1/(t1*t1 + t2*t2);
    *x = c*(*x)*t1 + *y*t2;
    *y = c*(*y)*t1 - oldx*t2;
}

void flame_rectangles(double* x, double* y) // Rectangles (Variation 40)
{
    double p1, p2; // x; y
    p1 = 0.25;
    p2 = 0.5;
    // nombre de rectangles : 1/(p1*p2*4)
    *x = (2*(int)(*x/p1) + 1)*p1 - *x;
    *y = (2*(int)(*y/p2) + 1)*p2 - *y;
}

void flame_arch(double* x, double* y) // Arch (Variation 41)
{
    double k = FLAME_KSY;
    double arch = 1.0;
    *x = sin(k*M_PI*arch);
    *y = *x*(*x)/cos(k*M_PI*arch);
}

void flame_tangent(double* x, double* y) // Tangent (Variation 42)
{
    *x = sin(*x)/cos(*y);
    *y = tan(*y);
}

void flame_square(double* x, double* y) // Square (Variation 43)
{
    *x = FLAME_KSY - 0.5;
    *y = FLAME_KSY - 0.5;
}

void flame_rays(double* x, double* y) // Rays (Variation 44)
{
    FLAME_R;
    double rays = 25;
    double c = rays*tan(FLAME_KSY*M_PI*rays)/r/r;
    *x = c*cos(*x);
    *y = c*sin(*y);
}

void flame_blade(double* x, double* y) // Blade (Variation 45)
{
    FLAME_R; FLAME_OLDX;
    double k = FLAME_KSY;
    double blade = 3.0;
    double c = k*r*blade;
    *x *= cos(c) + sin(c);
    *y = oldx*(cos(c) - sin(c));
}

void flame_secant(double* x, double* y) // Secant (Variation 46)
{
    FLAME_R;
    double secant = 168; // espace interne : 1/s
    *y = 1/secant/cos(secant*r);
}

void flame_twintrian(double* x, double* y) // Twintrian (Variation 47)
{
    FLAME_R; FLAME_OLDX;
    double k = FLAME_KSY;
    double twintrian = 3;
    double c = k*r*twintrian;
    double s = sin(c);
    double t = log10(s*s) + cos(c);
    *x *= t;
    *y = oldx*(t - M_PI*s);
}

void flame_cross(double* x, double* y) // Cross (Variation 48)
{
    double c = sqrt(pow(*x*(*x) - *y*(*y), -2));
    *x *= c;
    *y *= c;
}

/* non utilisée */
void flame_random(double* x, double* y) // Cross (Variation 48)
{
    //algorithms[randinrange(0, FLAME_NUM_VARIATION-2)](x, y);
}
