program Courbe3D;

uses Crt,Graph,Grafix;

var x,y,z     : array[1..4] of real;
    affx,affy : array[1..4] of integer;
    cos1,sin1 : real;
    cos2,sin2 : real;
    agr       : integer;
    ecran,mode: integer;
    pn        : real;

procedure Angle(x,y : real);
begin
     cos1:=cos(x*pi/180);
     sin1:=sin(x*pi/180);
     cos2:=cos(y*pi/180);
     sin2:=sin(y*pi/180);
end;

procedure Zoom(z : integer);
begin
     agr:=z;
end;

procedure Calcule2D(a : integer ; x,y,z : real);
var xyz : real;
begin
     xyz:=cos1*x+sin1*y;
     y:=cos1*y-sin1*x;
     x:=xyz;
     xyz:=cos2*y+sin2*z;
     z:=cos2*z-sin2*y;
     y:=xyz;
     affx[a]:=trunc(x*(1-z/1000))+320;
     affy[a]:=trunc(-y*(1-z/1000))+240;
end;

function Fonction(x,y : real) : real;
begin
     Fonction:=10*sin(sqrt(x*x+y*y))/(sqrt(x*x+y*y));
end;

procedure Affiche;
var col : integer;
begin
     FillRect(affx[1],affy[1],affx[2],affy[2],affx[3],affy[3],affx[4],affy[4],blue);
end;

procedure Trace(xmin,xmax,ymin,ymax : real ; xdiv,ydiv : integer);
var a,b : integer;
begin
     setcolor(white);
     for a:=0 to xdiv-1 do
     for b:=0 to ydiv-1 do
     begin
          x[1]:=xmin+(xmax-xmin)*a/xdiv;
          y[1]:=ymin+(ymax-ymin)*b/ydiv;
          z[1]:=Fonction(x[1],y[1]);
          Calcule2D(1,x[1]*agr,y[1]*agr,z[1]*agr);
          x[2]:=xmin+(xmax-xmin)*(a+1)/xdiv;
          y[2]:=ymin+(ymax-ymin)*b/ydiv;
          z[2]:=Fonction(x[2],y[2]);
          Calcule2D(2,x[2]*agr,y[2]*agr,z[2]*agr);
          x[3]:=xmin+(xmax-xmin)*(a+1)/xdiv;
          y[3]:=ymin+(ymax-ymin)*(b+1)/ydiv;
          z[3]:=Fonction(x[3],y[3]);
          Calcule2D(3,x[3]*agr,y[3]*agr,z[3]*agr);
          x[4]:=xmin+(xmax-xmin)*a/xdiv;
          y[4]:=ymin+(ymax-ymin)*(b+1)/ydiv;
          z[4]:=Fonction(x[4],y[4]);
          Calcule2D(4,x[4]*agr,y[4]*agr,z[4]*agr);
          Affiche;
     end;
end;

begin
     ecran:=VGA;
     mode:=2;
     InitGraph(ecran,mode,'');
     SetBkColor(black);
     SetColor(white);
     ClearDevice;
     Angle(-20,120);
     Zoom(15);
     Trace(-15,15,-15,15,101,101);
     Readln;
     CloseGraph;
end.


program Courbe3D;

uses Crt,Graph,Grafix;

var x,y,z     : array[1..4] of real;
    affx,affy : array[1..4] of integer;
    cos1,sin1 : real;
    cos2,sin2 : real;
    agr       : integer;
    ecran,mode: integer;
    prodsca   : real;
    vxl,vyl,vzl : real;

procedure Angle(x,y : real);
begin
     cos1:=cos(x*pi/180);
     sin1:=sin(x*pi/180);
     cos2:=cos(y*pi/180);
     sin2:=sin(y*pi/180);
     vxl:=-1/sqrt(3);
     vyl:=-1/sqrt(3);
     vzl:=+1/sqrt(3);
end;

procedure Zoom(z : integer);
begin
     agr:=z;
end;

procedure Calcule2D(a : integer ; xt,yt,zt : real);
var xyz : real;
begin
     xyz:=cos1*xt+sin1*yt;
     y[a]:=cos1*yt-sin1*xt;
     x[a]:=xyz;
     xyz:=cos2*y[a]+sin2*z[a];
     z[a]:=cos2*z[a]-sin2*y[a];
     y[a]:=xyz;
     affx[a]:=trunc(x[a]*(1-z[a]/1000))+320;
     affy[a]:=trunc(-y[a]*(1-z[a]/1000))+240;
end;

function Fonction(x,y : real) : real;
begin
     Fonction:=100*sin(sqrt(x*x+y*y))/(sqrt(x*x+y*y));
end;

Procedure CalculeReflect;
var nx,ny,nz : real;
begin
     nx:=(y[2]-y[1])*(z[3]-z[1])-(y[3]-y[1])*(z[2]-z[1]);
     ny:=(x[3]-x[1])*(z[2]-z[1])-(x[2]-x[1])*(z[3]-z[1]);
     nz:=(x[2]-x[1])*(y[3]-y[1])-(x[3]-x[1])*(y[2]-y[1]);

     prodsca:=(nx*vxl+ny*vyl+nz*vzl)/sqrt(nx*nx+ny*ny+nz*nz);
end;

procedure Affiche;
begin
     setcolor(0);
     FillRect(affx[1],affy[1],affx[2],affy[2],affx[3],affy[3],affx[4],affy[4],trunc(abs(-14*prodsca+1)));
end;

procedure Trace(xmin,xmax,ymin,ymax : real ; xdiv,ydiv : integer);
var a,b : integer;
begin
     for a:=0 to 15 do
     begin
          SetPalette(a,a);
          SetRGBPalette(a,a*4,a*4,a*4);
     end;
     for a:=0 to xdiv-1 do
     for b:=0 to ydiv-1 do
     begin
          x[1]:=xmin+(xmax-xmin)*a/xdiv;
          y[1]:=ymin+(ymax-ymin)*b/ydiv;
          z[1]:=Fonction(x[1],y[1]);
          Calcule2D(1,x[1]*agr,y[1]*agr,z[1]*agr);
          x[2]:=xmin+(xmax-xmin)*(a+1)/xdiv;
          y[2]:=ymin+(ymax-ymin)*b/ydiv;
          z[2]:=Fonction(x[2],y[2]);
          Calcule2D(2,x[2]*agr,y[2]*agr,z[2]*agr);
          x[3]:=xmin+(xmax-xmin)*(a+1)/xdiv;
          y[3]:=ymin+(ymax-ymin)*(b+1)/ydiv;
          z[3]:=Fonction(x[3],y[3]);
          Calcule2D(3,x[3]*agr,y[3]*agr,z[3]*agr);
          x[4]:=xmin+(xmax-xmin)*a/xdiv;
          y[4]:=ymin+(ymax-ymin)*(b+1)/ydiv;
          z[4]:=Fonction(x[4],y[4]);
          Calcule2D(4,x[4]*agr,y[4]*agr,z[4]*agr);
          CalculeReflect;
          Affiche;
     end;
end;

begin
     ecran:=VGA;
     mode:=2;
     InitGraph(ecran,mode,'');
     SetBkColor(black);
     SetColor(white);
     ClearDevice;
     Angle(-20,120);                               {-20,120              }
     Zoom(15);                                     {15                   }
     Trace(-15,15,-15,15,101,101);                 {-15,15,-15,15,101,101}
     Readln;
     