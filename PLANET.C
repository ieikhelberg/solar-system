#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
double t,Vx[ 100],Vy[100],summx,summy,r;
double  m[100],h,G,tmax,x[100],y[100],x__,y__,mz;
double k1ux[100],k1uy[100],k2ux[100],k2uy[100],k3ux[100],k3uy[100],k4ux[100],k4uy[100];
double k1x[100],k1y[100],k2x[100],k2y[100],k3x[100],k3y[100],k4x[100],k4y[100];
double dy[100],dx[100],dux[100],duy[100],xst[100],yst[100],sw,Vx1,Vy1,m1;
int i,j,k,numj,loop,numi,j1,i1,min,max;

void main(void)
{

int Driver,Mode;

loop=0;
mz=6.e24;
k=80  ;/*Количество планет*/
G=6.67e-11;
for(i=0;i<k;i++)
  {
    sw=rand();
    m[i]=fabs(sw)*1.e23;
    sw=rand()-32767./2.;
    x[i]=sw*3.5e7;
    sw=rand()-32767./2.;
    y[i]=sw*3.5e7;
    sw=rand()-32767./2.;
    Vx[i]=0.;
    sw=rand();
    Vy[i]=0.;



  }



h=36000.;
tmax=24.*365.*h*30.;
Driver=DETECT;
initgraph(&Driver,&Mode,"");
for(t=0.;t<=tmax;t+=h)
 {
   for(i=0;i<k;i++)
     {
     loop=0;
     summx=0.;
     summy=0.;



 /* 1  wychislenie uskorenij*/
     summx=0.;
     summy=0.;
      for(j=0;j<k;j++)
	   {
	    if(i!=j)
	    {
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
            summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/
	    if(sqrt(r)<1e9){numj=j;numi=i;}

	    }
	    }
            x__=-summx/m[i];
	    y__=-summy/m[i];
	    if(sqrt((x__*x__+y__*y__))>10.)
	    loop=1;
	    if(loop)
	      {
		max=max(numj,numi);min=min(numj,numi);
		for(j1=0,i1=0;j1<k;j1++)
		  {
		    if(j1!=numj&&j1!=numi)
		       {
				  m[i1]=m[j1];
				  Vx[i1]=Vx[j1];
				  Vy[i1]=Vy[j1];
				  x[i1]=x[j1];
				  y[i1]=y[j1];
				  i1++;
			}

			if(j1==min)
			   {
			     m[i1]=m[j1]+m[max];
			     Vx[i1]=Vx[j1]+Vx[max];
			     Vy[i1]=Vy[j1]+Vy[max];
			     x[i1]=x[j1];
			     y[i1]=y[j1];
			     i1++;
			    }

		  }  k=k-1;t=t-h;

	      }






  xst[i]=x[i];
  yst[i]=y[i];
 if(loop==0)
 {
	    x__=-summx/m[i];
	    y__=-summy/m[i];
/*  1 end wychislenie uskorenij */
	   k1ux[i]=h*x__;
	   k1x[i]=h*Vx[i];
	   k1uy[i]=h*y__;
	   k1y[i]=h*Vy[i];
	   x[i]=xst[i]+k1x[i]/2.;
	   y[i]=yst[i]+k1y[i]/2.;
 /*  2 wychislenie uskorenij*/
     summx=0.;
     summy=0.;
      for(j=0;j<k;j++)
	   {
	    if(i!=j)
	    {
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
	    summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/
	    }
	   }
	    x__=-summx/m[i];
	    y__=-summy/m[i];
/*  2  end wychislenie uskorenij */
	   k2ux[i]=h*x__;
	   k2x[i]=h*(Vx[i]+k1ux[i]/2.);

	   k2uy[i]=h*y__;
	   k2y[i]=h*(Vy[i]+k1uy[i]/2.);
	   y[i]=yst[i]+k2y[i]/2.;
	   x[i]=xst[i]+k2x[i]/2.;
 /*  4 wychislenie uskorenij*/
     summx=0.;
     summy=0.;
      for(j=0;j<k;j++)
	   {
	    if(i!=j)
	    {
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
	    summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/
	    }
	   }
	    x__=-summx/m[i];
	    y__=-summy/m[i];
/*  3  end wychislenie uskorenij */

	   k3ux[i]=h*x__;
	   k3x[i]=h*(Vx[i]+k2ux[i]/2.);

	   k3uy[i]=h*y__;
	   k3y[i]=h*(Vy[i]+k2uy[i]/2.);
	   y[i]=yst[i]+k3y[i];
	   x[i]=xst[i]+k3x[i];
 /*  3 wychislenie uskorenij*/
     summx=0.;
     summy=0.;
      for(j=0;j<k;j++)
	   {
	    if(i!=j)
	    {
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */

	    summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/



	    }
	   }

	    x__=-summx/m[i];
	    y__=-summy/m[i];
/*  4  end wychislenie  uskorenij */
	   k4ux[i]=h*x__;
	   k4x[i]=h*(Vx[i]+k3ux[i]);
	   k4uy[i]=h*y__;
	   k4y[i]=h*(Vy[i]+k3uy[i]);
	   dx[i]=1./6.*(k1x[i]+2.*k2x[i]+2.*k3x[i]+k4x[i]);
	   dy[i]=1./6.*(k1y[i]+2.*k2y[i]+2.*k3y[i]+k4y[i]);
	   dux[i]=1./6.*(k1ux[i]+2.*k2ux[i]+2.*k3ux[i]+k4ux[i]);
	   duy[i]=1./6.*(k1uy[i]+2.*k2uy[i]+2.*k3uy[i]+k4uy[i]);
	   x[i]=xst[i]+dx[i];
	   y[i]=yst[i]+dy[i];
	   Vx1=Vx[i];
	   Vy1=Vy[i];
	   Vx[i]=Vx[i]+dux[i];
	   Vy[i]=Vy[i]+duy[i];

}

       }

      for(i=0;i<k;i++)
	{
	   setcolor(0);
	   circle(xst[i]/6.5e11*getmaxy()/2.+getmaxx()/2.,
	   yst[i]/6.5e11*getmaxy()/2.+getmaxy()/2.,2);
	   putpixel(xst[i]/6.5e11*getmaxy()/2.+getmaxx()/2.,
	   yst[i]/6.5e11*getmaxy()/2.+getmaxy()/2.,i+2);
	   setcolor(i+2);
	   circle(x[i]/6.5e11*getmaxy()/2.+getmaxx()/2.,
	   y[i]/6.5e11*getmaxy()/2.+getmaxy()/2.,2);

	}
      }
  closegraph();
}