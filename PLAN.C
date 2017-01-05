#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
double x[100],h,y[100],xs[100],ys[100],maxrast,Vx[ 100],Vy[100],k4ux[100],k4uy[100],uvel;
int k,d[100],a,maxx,maxy,loop,col[100],plan;
char *im[1000];
double perx,pery,z;
char *str1[31];
main(void)
{

double t,summx,summy,r;
double m[100],G,tmax,x__,y__,mz;
double x0[100],y0[100],Vx0[100],Vy0[100];
double ;
double dy[100],dx[100],dux[100],duy[100],xst[100],yst[100],sw,m1;
float dp[100];
int Driver,Mode;

void setka(void);
void risowan(int plan,double tt);
void koment(void);
void wind(void);
int i,j,loop,j1,i1,min,max;
loop=0;
mz=5.98e24; /*Масса Земли*/


k=5;/*Количество планет*/




G=6.67e-11;

/*Параметры для Солнца*/
m[0]=333000.0*mz;
x0[0]=0.0;
y0[0]=0.0;
Vx0[0]=0.1;
Vy0[0]=0.0;
d[0]=0;
dp[0]=2400000000.;
col[0]=14;

str1[0]="Солнце  0";




/*Параметры для Меркурия*/
m[1]=mz*0.055;
x0[1]=58000000000.;
y0[1]=0.;
Vx0[1]=0.;
Vy0[1]=2.*3.1415/24./88./3600.*x0[1];
d[1]=0;
dp[1]=4900000.;
col[1]=2;
str1[1]="Меркурий1";

/*Параметры для Венеры*/
m[2]=mz*0.82;
x0[2]=108000000000.0;
y0[2]=0.0;
Vy0[2]=2.*3.1415/24./225./3600*x0[2];
Vx0[2]=0.0;
d[2]=0;
dp[2]=12100000;
col[2]=3;
str1[2]="Венера  2";



/*╧Параметры для Земли*/
m[3]=mz;
x0[3]=1.498e11; /*m*/
y0[3]=0.0;
Vx0[3]=0.0;
Vy0[3]=2.*3.1415*x0[3]/24./365./3600.;
d[3]=0;
dp[3]=12756000.;
col[3]=11;
str1[3]="Земля   3";


/*Параметры для Марса*/
m[4]=mz*0.11;
y0[4]=0.;
x0[4]=2.28e11;
Vx0[4]=0.0;
Vy0[4]=2.*3.1415/24./(365.*1.881)/3600.*x0[4];
d[4]=0;
dp[4]=6800000.;
col[4]=12;
str1[4]="Марс    4";




/*Параметры для Юпитера*/
m[5]=mz*318.;
y0[5]=0.;
x0[5]=7.78e11;
Vx0[5]=0.0;
Vy0[5]=2.*3.1415/24./(365.*11.86)/3600.*x0[5];
d[5]=0;
dp[5]=142000000.;
col[5]=6;
str1[5]="Юпитер  5";


/*Параметры для Сатурна*/
m[6]=mz*95.;
y0[6]=0.;
x0[6]=14.26e11;
Vx0[6]=0.0;
Vy0[6]=2.*3.1415/24./(365.*29.46)/3600.*x0[6];
d[6]=0;
dp[6]=120000000.;
col[6]=14;
str1[6]="Сатурн  6";













/*Параметры для Урана*/
m[7]=mz*14.6;
y0[7]=0.;
x0[7]=28.69e11;
Vx0[7]=0.0;
Vy0[7]=2.*3.1415/24./(365.*84.01)/3600.*x0[7];
d[7]=0;
dp[7]=49567000.;
col[7]=2;
str1[7]="Уран    7";











/*Параметры для Нептуна*/
m[8]=mz*17.2;
y0[8]=0.;
x0[8]=44.96e11;
Vx0[8]=0.0;
Vy0[8]=2.*3.1415/24./(365.*164.8)/3600.*x0[8];
d[8]=0;
dp[8]=50000000.;
col[8]=14;
str1[8]="Нептун  8";

/*Параметры для Плутона*/
m[9]=1.3e22;
y0[9]=0.;
x0[9]=59.00e11;
Vx0[9]=0.0;
Vy0[9]=2.*3.1415/24./(365.*247.7)/3600.*x0[9];
d[9]=0;
dp[9]=2800000.;
col[9]=8;
str1[9]="Плутон  9";
uvel=2.;





for(i=0;i<k;i++)
 {
 xs[i]=x0[i];
 ys[i]=y0[i];
 x[i]=x0[i];
 y[i]=y0[i];
 Vx[i]=Vx0[i];
 Vy[i]=Vy0[i];

 }
 maxrast=0.;
for(i=0;i<k;i++)
 {
  maxrast=max(x0[i],maxrast);
 }
maxrast=maxrast*1.1;
perx=0.0;pery=0.0;
h=1000.;/* schag integrirowanija (sec.)*/
tmax=24.*365.*3600.*25.;
Driver=DETECT;
initgraph(&Driver,&Mode,"");
loop=0;z=20.;
plan=0;
maxx=getmaxx();
maxy=getmaxy();
settextstyle(0,0,1);
/*setactivepage(0);*/
wind();
/*setcolor(14);*/


for(t=.1;;t+=h,loop++)
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

		setka();


   a=getch();
   switch(a)
   {
   case 45 : { wind();maxrast*=uvel;z*=uvel;
		  for(i=0;i<k;i++)
	     {
			d[i]=dp[i]/maxrast*240.;

	     }
		 break;
	     }
   case 43 :{ wind();maxrast/=uvel;z/=uvel;
	     for(i=0;i<k;i++)
	     {
	      d[i]=dp[i]/maxrast*240.;
	      if(d[plan]>200){maxrast*=uvel;z*=uvel;break;}
	     }
		 break;
		  }

   case 77 : perx+=10;wind();break;
   case 80 : pery+=10;wind();break;
   case 75 : perx-=10;wind();break;
   case 72 : pery-=10;wind();break;
   case 48 : plan=0;wind();break;
   case 49 : plan=1;wind();break;
   case 50 : plan=2;wind();break;
   case 51 : plan=3;wind();break;
   case 52 : plan=4;wind();break;
   case 53 : plan=5;wind();break;
   case 54 : plan=6;wind();break;
   case 55 : plan=7;wind();break;
   case 56 : plan=8;wind();break;
   case 57 : plan=9;wind();break;

   case 27 : exit(1);break;

case 112 :  wind();risowan(plan,t);getch();break;





   }
  }
 if(d[plan]>200){maxrast*=uvel;z*=uvel;}
	if(d[plan]>200){maxrast/=uvel;z/=uvel;}

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



   x__=-summx/m[i];
   y__=-summy/m[i];

      x[i]=x0[i]+Vx0[i]*t+x__*t*t/2.;
      y[i]=y0[i]+Vy0[i]*t+y__*t*t/2.;

      t*t*(x[i]-x[j])/(2.*pow(SQR(x[j])*x[i]+SQR(y[i])-2.*y[j]*y[i]+(y[j]),3/2))





      Vx[i]=Vx0[i]+x__*t;
      Vy[i]=Vy0[i]+y__*t;

  xst[i]=x[i];
  yst[i]=y[i];


       }
       if(loop>=1)
       {
       risowan(plan,t);
       loop=0;
       }


       }
  getch();
  }


void risowan(int plan,double tt)
{

int i;
char str[10];

koment();
gcvt(tt/24./3600.,4,str);
  setcolor(14);
  outtextxy(maxx*0.9,6,"Время:");
  outtextxy(maxx*0.89,15,"(в сут.)");


  setfillstyle(SOLID_FILL,1);

  bar(maxx*0.9,maxy*0.1,maxx*0.999,maxy*0.12);

  outtextxy(maxx*0.9,maxy*0.1,str);

	for(i=0;i<k;i++)
	{
	   setcolor(0);
	   setfillstyle(SOLID_FILL,0);
	if(fabs((xs[i])/maxrast*maxy/2.+maxx/2.+perx)<maxy+(maxx-maxy)/2. &&
	   fabs((ys[i])/maxrast*maxy/2.+maxy/2.+pery)<maxy+(maxx-maxy)/2. &&
	   fabs((xs[i])/maxrast*maxy/2.+maxx/2.+perx)>(maxx-maxy)/2. &&
	   fabs((ys[i])/maxrast*maxy/2.+maxy/2.+pery)>0)

	  if(i!=plan)
	   sector((xs[i]/*-x[plan]*/)/maxrast*maxy/2.+maxx/2.+perx,
		(ys[i]/*-y[plan]*/)/maxrast*maxy/2.+maxy/2.+pery,0,360,d[i],d[i]);

	}

	for(i=0;i<k;i++)
	{
		setcolor(col[i]);
		setfillstyle(SOLID_FILL,col[i]);

	if(fabs((x[i]-x[plan])/maxrast*maxy/2.+maxx/2.+perx)<maxy+(maxx-maxy)/2. &&
		fabs((y[i]-y[plan])/maxrast*maxy/2.+maxy/2.+pery)<maxy+(maxx-maxy)/2. &&
		fabs((x[i]-x[plan])/maxrast*maxy/2.+maxx/2.+perx)>(maxx-maxy)/2. &&
		fabs((y[i]-y[plan])/maxrast*maxy/2.+maxy/2.+pery)>0  )
	if(d[i]==0)

	 putpixel((x[i]-x[plan])/maxrast*maxy/2.+maxx/2.+perx,
	 (y[i]-y[plan])/maxrast*maxy/2.+maxy/2.+pery,col[i]);

	 else

		sector((x[i]-x[plan])/maxrast*maxy/2.+maxx/2.+perx,
		(y[i]-y[plan])/maxrast*maxy/2.+maxy/2.+pery,0,360,d[i],d[i]);
		setka();
		xs[i]=x[i]-x[plan];
		ys[i]=y[i]-y[plan];




	 }




}

     void setka(void)
   {
     float i;
     char str[10];
     float t=5;

     setcolor(14);
     rectangle ((maxx-maxy)/2.,0,(maxx+maxy)/2.,maxy);
     setcolor(8);
     for(i=1;i<t;i++)

     {line((maxx-maxy)/2.,maxy/t*i,(maxx+maxy)/2.,maxy/t*i);
      line((maxx-maxy)/2.+maxy/t*i,0,(maxx-maxy)/2.+maxy/t*i,maxy);

      }
     setcolor(14);
  gcvt(maxrast/1000000./t,7,str);
  outtextxy(maxx*0.89,maxy*0.92,str);
  outtextxy(maxx*0.887,maxy*0.97,"(тыс.км.)");

   }

	void wind(void)
	{
	 int i,f;
	 setfillstyle(SOLID_FILL,1);
	 bar(maxx/6.*5.3,0,maxx,maxy);
	 bar(0,0,maxx/8.1,maxy);
	 setcolor(14);
	 rectangle(maxx/6.*5.3,0,maxx,maxy);
	 rectangle(0,0,maxx/8.1,maxy);
	 setfillstyle(SOLID_FILL,0);


	 for(i=0,f=8;i<10;i++,f+=35)
	 {
	 bar(26,f,maxx/8.5,f+10);
	 setcolor(14);
	 outtextxy(2,f,"Vt=");
	 rectangle(26,f,maxx/8.5,f+10);
	 setcolor(14);
	 if(i==plan)setcolor(4);
	 outtextxy(3,f+15,str1[i]);
	 setcolor(14);
	 }



	}


	void koment(void)
	{
	 int i,f;
	 char str[20];

	 setfillstyle(SOLID_FILL,0);

         for(i=0,f=8;i<10;i++,f+=35)
	 {
	 bar(27,f+1,maxx/8.5-1,f+9);
	 }

	  setcolor(14);
	 for(i=0,f=33;i<10;i++,f+=35)
	 {


	 gcvt(sqrt(Vx[i]*Vx[i]+Vy[i]*Vy[i]),4,str);
	 outtextxy(28,f-23,str);
	/* gcvt(sqrt(k4ux[i]*k4ux[i]/h/h+k4uy[i]*k4uy[i]/h/h),3,str);*/

	/* outtextxy(2,f,"At=");
	 outtextxy(25,f,str);*/



	/* setfillstyle(SOLID_FILL,i+22);*/

	/* sector(3,h,0,360,2,2);*/
	 }

	}




