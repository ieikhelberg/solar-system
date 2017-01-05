#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
double x[100],y[100],xs[100],ys[100],maxrast;
int d[100],a,maxx,maxy,loop,k;
double perx,pery,z;
double t,Vx[ 100],Vy[100],summx,summy,r;
double m[100],h,G,tmax,x__,y__,mz;
double k1ux[100],k1uy[100],k2ux[100],k2uy[100],k3ux[100],k3uy[100],k4ux[100],k4uy[100];
double k1x[100],k1y[100],k2x[100],k2y[100],k3x[100],k3y[100],k4x[100],k4y[100];
double dy[100],dx[100],dux[100],duy[100],xst[100],yst[100],sw,m1,x1,y1;
int numj[100];
float dp[100];
void main(void)
{


int Driver,Mode,plan;
void slip(int i,int j);
void setka(int k,float j,float xzent,float yzent);
void risowan(int loop,int plan,double tt);
void koment(void);

int i,j,loop,j1,i1,min,max;
loop=0;
mz=6.e24; /*massa zemli*/
k=8  ;/*Количество планет*/
G=6.67e-11;

/*Параметры для Солнца*/
m[0]=333000.0*mz;
x[0]=0.0;
y[0]=0.0;
Vx[0]=0.0;
Vy[0]=0.0;
d[0]=0;
dp[0]=2400000000.;


/*Параметры для Меркурия*/
m[1]=mz*0.06;
x[1]=58000000000.;
y[1]=0.;
Vx[1]=0.;
Vy[1]=2000;
d[1]=0;
dp[1]=6000000.;

/*Параметры для Венеры*/
m[2]=mz*0.82;
x[2]=108000000000.0;
y[2]=0.0;
Vy[2]=2000;
Vx[2]=0.0;
d[2]=0;
dp[2]=12000000;


/*Параметры для Земли*/
m[3]=mz;
x[3]=1.498e11; /*m*/
y[3]=0.0;
Vx[3]=0.0;
Vy[3]=3000.;
d[3]=0;
dp[3]=12000000.;

/*Параметры для Луны*/
m[4]=mz/81.;
x[4]=x[3]+384000000.;
y[4]=0.;
Vx[4]=0.0;
Vy[4]=Vy[3]+2.*3.1415*384000000./27.333/24./3600.;
d[4]=0;
dp[4]=3473000.;

/*Параметры для Марса*/
m[5]=mz*0.11;
y[5]=0.;
x[5]=2.28e11;
Vx[5]=0.0;
Vy[5]=2000.;
d[5]=0;
dp[5]=6000000.;

/*Парамеры для Юпитера*/
m[6]=mz*318.;
y[6]=0.;
x[6]=-7.78e11;
Vx[6]=0.0;
Vy[6]=200.;
d[6]=0;
dp[6]=240000000.;

/*Парамеры для Сатурна*/
m[7]=mz*95.1;
y[7]=0.;
x[7]=14.26e11;
Vx[7]=0.0;
Vy[7]=200.;
d[7]=0;
dp[7]=120000000;

for(i=0;i<k;i++)
 {
 xs[i]=x[i];
 ys[i]=y[i];
 }
 maxrast=0.;
for(i=0;i<k;i++)
 {
  maxrast=max(x[i],maxrast);
  numj[i]=0;
 }
maxrast=maxrast*1.1;
perx=0.0;pery=0.0;
h=750.;/* schag integrirowanija*/
tmax=24.*365.*3600.*25.;
Driver=DETECT;
initgraph(&Driver,&Mode,"");
loop=0;z=20.;
plan=0;
maxx=getmaxx();
maxy=getmaxy();
koment();

for(t=0.;;/*t<=tmax;*/t+=h,loop++)
 {
  if(kbhit())
   {
    setfillstyle(SOLID_FILL,0);
    setcolor(0);
  for(i=0;i<k;i++)
	{
	   sector((xs[i])/maxrast*maxy/2.+maxx/2.+perx,
	   (ys[i])/maxrast*maxy/2.+maxy/2.+pery,0,360,d[i],d[i]);
	}

	   setka(0,z,perx,pery);


   a=getch();
   switch(a)
   {
   case 45 : { maxrast*=1.1;z*=1.1;
	     for(i=0;i<k;i++)
	     {
	      d[i]=dp[i]/maxrast*240.;
	     /* if(d[i]<=1)d[i]=1;*/
	      }
		 break;
	     }
   case 43 :{ maxrast/=1.1;z/=1.1;
	     for(i=0;i<k;i++)
	     {
	      d[i]=dp[i]/maxrast*240.;
	     /* if(d[i]<=1)d[i]=1;*/
	      }
		 break;
	     }

   case 77 : perx+=10;break;
   case 80 : pery+=10;break;
   case 75 : perx-=10;break;
   case 72 : pery-=10;break;
/*   case 48 : plan=0;break;
   case 49 : plan=1;break;
   case 50 : plan=2;break;
   case 51 : plan=3;break;
   case 52 : plan=4;break;
   case 53 : plan=5;break;
   case 54 : plan=6;break;
   case 55 : plan=7;break;*/


   case 27 : exit(1);break;
   case 112 :risowan(1,plan,t);getch();break;





   }
  }


   for(i=0;i<k;i++)

     {
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

	    }
	    }

  xst[i]=x[i];
  yst[i]=y[i];

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
	   Vx[i]=Vx[i]+dux[i];
	   Vy[i]=Vy[i]+duy[i];


	   for(j=0;j<k;j++)
	   {
	    if(i!=j)
	    {

	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);

	    if(sqrt(r)<4803000000.)
	     {
	     slip(i,j);

	     }


	    }
	   }








       }

       risowan(loop,plan,t);
       if(loop==40)loop=0;

       }
  getch();
  }

void slip(int i,int j)
{

 for(;;t+=h/10.)
 {




 /* 1  wychislenie uskorenij*/
     summx=0.;
     summy=0.;
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
            summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/


  xst[i]=x[i];
  yst[i]=y[i];

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
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
	    summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/
	    x__=-summx/m[i];
	    y__=-summy/m[i];
/*  2  end wychislenie uskorenij */
	   k2ux[i]=h*x__;
	   k2x[i]=h*(Vx[i]+k1ux[i]/2.);
	   k2uy[i]=h*y__;
	   k2y[i]=h*(Vy[i]+k1uy[i]/2.);
	   y[i]=yst[i]+k2y[i]/2.;
	   x[i]=xst[i]+k2x[i]/2.;
 /*  3 wychislenie uskorenij*/
     summx=0.;
     summy=0.;
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
	    summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/
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
	    r=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);/* rastoyanie */
	    summx+=G*m[i]*m[j]*(x[i]-x[j])/(r*sqrt(r));/*sila po osi x*/
	    summy+=G*m[i]*m[j]*(y[i]-y[j])/(r*sqrt(r));/*sila po osi y*/
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
	   Vx[i]=Vx[i]+dux[i];
	   Vy[i]=Vy[i]+duy[i];


  }

}


































  void setka(int k,float j,float xzent,float yzent)
   {
     int i;
     int mx,my,t;
     char str[10];
     float n;
     n=j;
     t=20.;

     mx=getmaxx();
     my=getmaxy();
     setcolor(k);
     rectangle ((mx-my)/2.,0,(mx+my)/2.,my);
     setcolor(k);
/*   line(mx/2.,0,xzent+mx/2.,my/2);
     line((mx-my)/2.,my/2.+yzent,(my+mx)/4.,my/2.+yzent);
     line(mx/2.,0,xzent+mx/2.,my);
     line((mx-my)/2.,my/2.+yzent,(my+mx)/2.,my/2.+yzent);*/
     gcvt(maxrast/1000000.,7,str);



  outtextxy(maxx*0.89,maxy*0.97,str);
  outtextxy(maxx*0.02,maxy*0.97,str);
  outtextxy(maxx*0.89,maxy*0.5,"0");
  outtextxy(maxx*0.1,maxy*0.5,"0");






    /* for(i=-n/2.;i<=n/2.;i+=1.)
     {*/
    /* if(i==0&&k!=0)setcolor(3);else*/ setcolor(k);
    /* line(my/n*i+xzent+mx/2.,0,my/n*i+xzent+mx/2.,my);*//*wertikal*/
    /* line((mx-my)/2.,my/n*i+my/2.+yzent,(my+mx)/2.,my/n*i+my/2.+yzent);*/ /*gorizont*/
    /* if(i==0&&k!=0)setcolor(k);*/
    /* }*/
   }
void risowan(int v,int plan,double tt)
{

int i;
char str[10];


 if(v==20)v=0;
       if(v==1)
	{

gcvt(tt/24./3600./365.,3,str);

  outtextxy(maxx*0.9,6,"Время:");

  setfillstyle(SOLID_FILL,0);

  bar(maxx*0.9,maxy*0.1,maxx,maxy*0.2);

  outtextxy(maxx*0.9,maxy*0.1,str);

	for(i=0;i<k;i++)
	{
	   setcolor(0);
	   setfillstyle(SOLID_FILL,0);
	if(fabs((xs[i])/maxrast*maxy/2.+maxx/2.+perx)<maxy+(maxx-maxy)/2. &&
	   fabs((ys[i])/maxrast*maxy/2.+maxy/2.+pery)<maxy+(maxx-maxy)/2. &&
	   fabs((xs[i])/maxrast*maxy/2.+maxx/2.+perx)>(maxx-maxy)/2. &&
	   fabs((ys[i])/maxrast*maxy/2.+maxy/2.+pery)>0)


	   sector((xs[i])/maxrast*maxy/2.+maxx/2.+perx,
	   (ys[i])/maxrast*maxy/2.+maxy/2.+pery,0,360,d[i],d[i]);
	}

	for(i=0;i<k;i++)
	{
	   setcolor(i+22);
	   setfillstyle(SOLID_FILL,i+22);

	if(fabs((x[i])/maxrast*maxy/2.+maxx/2.+perx)<maxy+(maxx-maxy)/2. &&
	   fabs((y[i])/maxrast*maxy/2.+maxy/2.+pery)<maxy+(maxx-maxy)/2. &&
	   fabs((x[i])/maxrast*maxy/2.+maxx/2.+perx)>(maxx-maxy)/2. &&
	   fabs((y[i])/maxrast*maxy/2.+maxy/2.+pery)>0  )
	if(d[i]==0)
	 putpixel((x[i])/maxrast*maxy/2.+maxx/2.+perx,
	 (y[i])/maxrast*maxy/2.+maxy/2.+pery,i+22);
	 else
	   sector((x[i])/maxrast*maxy/2.+maxx/2.+perx,
	   (y[i])/maxrast*maxy/2.+maxy/2.+pery,0,360,d[i],d[i]);
	   setka(24,z,perx,pery);
	   xs[i]=x[i];
	   ys[i]=y[i];
	   loop=0;
	 }
	}

}

   void koment(void)
   {
    int i,h;

    outtextxy(8,20,"Солнце  0");
    outtextxy(8,40,"Меркурий1");
    outtextxy(8,60,"Венера  2");
    outtextxy(8,80,"Земля   3");
    outtextxy(8,100,"Луна    4");
    outtextxy(8,120,"Марс    5");
    outtextxy(8,140,"Юпитер  6");
    outtextxy(8,160,"Сатурн  7");

    for(i=0,h=23;i<k;i++,h+=20)
    {
    setcolor(i+22);
    setfillstyle(SOLID_FILL,i+22);
    sector(3,h,0,360,2,2);
    }

   }



