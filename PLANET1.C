#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<GRAPHICS.h>
#include<stdlib.h>
double x[100],h,y[100],xs[100],ys[100],maxrast,Vx[ 100],Vy[100],k4ux[100],k4uy[100],uvel;
int k,d[100],a,maxx,maxy,loop,col[100],plan;
char *im[1000];
double perx,pery,z;
char *str1[31];
main(void)
{

	double t,summx,summy,r,sss;
	double m[100],G,tmax,x__,y__,mz;
	double k1ux[100],k1uy[100],k2ux[100],k2uy[100],k3ux[100],k3uy[100];
	double k1x[100],k1y[100],k2x[100],k2y[100],k3x[100],k3y[100],k4x[100],k4y[100];
	double dy[100],dx[100],dux[100],duy[100],xst[100],yst[100],sw,m1;
	float dp[100];
	int Driver,Mode;

	void setka(void);
	void risowan(int plan,double tt);
	void koment(void);
	void wind(void);
	int i,j,loop,j1,i1,min,max;
	loop=0;
mz=5.98e24; /*Œ áá  ‡¥¬«¨*/

k=31; /*Š®«¨ç¥áâ¢® ¯« ­¥â*/

	G=6.67e-11;

/* à ¬¥âàë ¤«ï ‘®«­æ */
	m[0]=333000.0*mz;
	x[0]=0.0;
	y[0]=0.0;
	Vx[0]=0.1;
	Vy[0]=0.0;
	d[0]=0;
	dp[0]=2400000000.;
	col[0]=14;

	str1[0]="Sun 0";

/* à ¬¥âàë ¤«ï Œ¥àªãà¨ï*/
	m[1]=mz*0.055;
	sss=rand();
	x[1]=58000000000.;
	y[1]=.0;
	Vx[1]=2.*3.1415/24./88./3600.*y[1];
	Vy[1]=2.*3.1415/24./88./3600.*x[1];
	d[1]=0;
	dp[1]=4900000.;
	col[1]=2;
	str1[1]="Mercury 1";

/* à ¬¥âàë ¤«ï ‚¥­¥àë*/
	m[2]=mz*0.82;
	sss=rand();
	x[2]=108000000000.;
	y[2]=.0;
	Vy[2]=2.*3.1415/24./225./3600*x[2];
	Vx[2]=2.*3.1415/24./225./3600*y[2];
	d[2]=0;
	dp[2]=12100000;
	col[2]=3;
	str1[2]="Venus 2";


/* à ¬¥âàë ¤«ï ‡¥¬«¨*/
	m[3]=mz;
	sss=rand();
x[3]=1.498e11; /*m*/
	y[3]=.0;
	Vx[3]=2.*3.1415/24./365./3600.*y[3];
	Vy[3]=2.*3.1415/24./365./3600.*x[3];
	d[3]=0;
	dp[3]=12756000.;
	col[3]=11;
	str1[3]="Earth";


/* à ¬¥âàë ¤«ï Œ àá */
	m[4]=mz*0.11;
	sss=rand();
	x[4]=2.28e11;
	y[4]=.0;
	Vx[4]=2.*3.1415/24./(365.*1.881)/3600.*y[4];
	Vy[4]=2.*3.1415/24./(365.*1.881)/3600.*x[4];
/*y[4]=0.;
x[4]=2.28e11;
Vx[4]=0.0;
Vy[4]=2.*3.1415/24./(365.*1.881)/3600.*x[4];*/
	d[4]=0;
	dp[4]=6800000.;
	col[4]=12;
	str1[4]="Mars";
			  /*Satellites Œ àá */
			  /*”®¡®á*/
	m[11]=11.e15;
	y[11]=y[4];
	x[11]=x[4]+9380000.;
	Vx[11]=Vx[4];
	Vy[11]=Vy[4]+2.*3.1415*9380000./(0.319*24.*3600.);
	d[11]=0;
	dp[11]=14000.*2.;
	col[11]=12;
	str1[11]="Fobos";
			  /*„¥©¬®á*/
	m[12]=18.e14;
	y[12]=y[4];
	x[12]=x[4]+23460000.;
	Vx[12]=Vx[4];
	Vy[12]=Vy[4]+2.*3.1415*23460000./(1.263*24.*3600.);
	d[12]=0;
	dp[12]=8000.*2.;
	col[12]=12;
	str1[12]="Deymos";




/* à ¬¥âàë ¤«ï ž¯¨â¥à */
	m[5]=mz*318.;
	y[5]=0.;
	x[5]=7.78e11;
	Vx[5]=0.0;
	Vy[5]=2.*3.1415/24./(365.*11.86)/3600.*x[5];
	d[5]=0;
	dp[5]=142000000.;
	col[5]=6;
	str1[5]="Jupiter 5";
			/*Satellites ž¯¨â¥à */
			/*ˆ®*/
	m[13]=894.e20;
	y[13]=y[5];
	x[13]=x[5]+421600000;
	Vx[13]=0.0;
	Vy[13]=Vy[5]+2.*3.1415*421600000./(1.769*24.*3600.);
	d[13]=0;
	dp[13]=1815000.*2.;
	col[13]=12;
	str1[13]="ˆ®";
			/*…¢à®¯ */
	m[14]=480.e20;
	y[14]=y[5];
	x[14]=x[5]+670900000;
	Vx[14]=0.0;
	Vy[14]=Vy[5]+2.*3.1415*670900000./(3.551*24.*3600.);
	d[14]=0;
	dp[14]=1569000.*2.;
	col[14]=12;
	str1[14]="Europe";
			/*ƒ ­¨¬¥¤*/
	m[15]=1482.3e20;
	y[15]=y[5];
	x[15]=x[5]+1070000000;
	Vx[15]=0.0;
	Vy[15]=Vy[5]+2.*3.1415*1070900000./(7.155*24.*3600.);
	d[15]=0;
	dp[15]=2631000.*2.;
	col[15]=12;
	str1[15]="Ganymed";
			/*Š «¨áâ®*/
	m[16]=1076.3e20;
	y[16]=y[5];
	x[16]=x[5]+1883000000;
	Vx[16]=0.0;
	Vy[16]=Vy[5]+2.*3.1415*1883000000./(16.689*24.*3600.);
	d[16]=0;
	dp[16]=2400000.*2.;
	col[16]=12;
	str1[16]="Kalisto";

/* à ¬¥âàë ¤«ï ‘ âãà­ */
	m[6]=mz*95.;
	y[6]=0.;
	x[6]=14.26e11;
	Vx[6]=0.0;
	Vy[6]=2.*3.1415/24./(365.*29.46)/3600.*x[6];
	d[6]=0;
	dp[6]=120000000.;
	col[6]=14;
	str1[6]="‘Saturn 6";
			/*Satellites ‘ âãà­ */
			/*Œ¨¬ á*/
	m[17]=0.38e20;
	y[17]=y[6];
	x[17]=x[6]+185520000.;
	Vx[17]=0.0;
	Vy[17]=Vy[6]+2.*3.1415*185520000./(0.942*24.*3600.);
	d[17]=0;
	dp[17]=195000.*2.;
	col[17]=14;
	str1[17]="Mimas";
			/*­æ¥« ­¤*/
	m[18]=0.84e20;
	y[18]=y[6];
	x[18]=x[6]+238020000.;
	Vx[18]=0.0;
	Vy[18]=Vy[6]+2.*3.1415*238020000./(1.37*24.*3600.);
	d[18]=0;
	dp[18]=250000.*2.;
	col[18]=14;
	str1[18]="Enceladus";
			/*’¥ä¨ï*/
	m[19]=7.55e20;
	y[19]=y[6];
	x[19]=x[6]+294660000.;
	Vx[19]=0.0;
	Vy[19]=Vy[6]+2.*3.1415*294660000./(1.88*24.*3600.);
	d[19]=0;
	dp[19]=525000.*2.;
	col[19]=14;
	str1[19]="’¥ä¨ï";
			/*„¨®­ */
	m[20]=10.5e20;
	y[20]=y[6];
	x[20]=x[6]+377400000.;
	Vx[20]=0.0;
	Vy[20]=Vy[6]+2.*3.1415*377400000./(2.737*24.*3600.);
	d[20]=0;
	dp[20]=560000.*2.;
	col[20]=14;
	str1[20]="Dion";
			/*¥ï*/
	m[21]=24.9e20;
	y[21]=y[6];
	x[21]=x[6]+527040000.;
	Vx[21]=0.0;
	Vy[21]=Vy[6]+2.*3.1415*527040000./(4.518*24.*3600.);
	d[21]=0;
	dp[21]=765000.*2.;
	col[21]=14;
	str1[21]="Reya";
			/*’¨â ­*/
	m[22]=1350.e20;
	y[22]=y[6];
	x[22]=x[6]+1221850000.;
	Vx[22]=0.0;
	Vy[22]=Vy[6]+2.*3.1415*1221850000./(15.945*24.*3600.);
	d[22]=0;
	dp[22]=2575000.*2.;
	col[22]=14;
	str1[22]="Titan";
			/*Ÿ¯¥â*/
	m[23]=18.8e20;
	y[23]=y[6];
	x[23]=x[6]+3561300000.;
	Vx[23]=0.0;
	Vy[23]=Vy[6]+2.*3.1415*3561300000./(79.331*24.*3600.);
	d[23]=0;
	dp[23]=720000.*2.;
	col[23]=14;
	str1[23]="Yapet";



/* à ¬¥âàë ¤«ï “à ­ */
	m[7]=mz*14.6;
	y[7]=0.;
	x[7]=28.69e11;
	Vx[7]=0.0;
	Vy[7]=2.*3.1415/24./(365.*84.01)/3600.*x[7];
	d[7]=0;
	dp[7]=49567000.;
	col[7]=2;
	str1[7]="Uranus 7";
		      /*Satellites “à ­ */
		      /*Œ¨à ­¤ */
	m[24]=.689e20;
	y[24]=y[7];
	x[24]=x[7]+129780000.;
	Vx[24]=0.0;
	Vy[24]=Vy[7]+2.*3.1415*129780000./(1.414*24.*3600.);
	d[24]=0;
	dp[24]=235000.*2.;
	col[24]=2;
	str1[24]="Miranda";

			/*€à¨í«ì*/
	m[25]=12.6e20;
	y[25]=y[7];
	x[25]=x[7]+191240000.;
	Vx[25]=0.0;
	Vy[25]=Vy[7]+2.*3.1415*191240000./(2.52*24.*3600.);
	d[25]=0;
	dp[25]=580000.*2.;
	col[25]=2;
	str1[25]="Ariel";

			/*“¬¡à¨í«ì*/
	m[26]=13.3e20;
	y[26]=y[7];
	x[26]=x[7]+264970000.;
	Vx[26]=0.0;
	Vy[26]=Vy[7]+2.*3.1415*264970000./(4.144*24.*3600.);
	d[26]=0;
	dp[26]=585000.*2.;
	col[26]=2;
	str1[26]="Umbriel";

			/*’¨â ­¨ï*/
	m[27]=34.8e20;
	y[27]=y[7]			;
	x[27]=x[7]+435840000.;
	Vx[27]=0.0;
	Vy[27]=Vy[7]+2.*3.1415*435840000./(8.706*24.*3600.);
	d[27]=0;
	dp[27]=790000.*2.;
	col[27]=2;
	str1[27]="Titania";

			/*Ž¡¥à®­*/
	m[28]=30.3e20;
	y[28]=y[7];
	x[28]=x[7]+582600000.;
	Vx[28]=0.0;
	Vy[28]=Vy[7]+2.*3.1415*582600000./(13.463*24.*3600.);
	d[28]=0;
	dp[28]=760000.*2.;
	col[28]=2;
	str1[28]="Oberon";



/* à ¬¥âàë ¤«ï ¥¯âã­ */
	m[8]=mz*17.2;
	y[8]=0.;
	x[8]=44.96e11;
	Vx[8]=0.0;
	Vy[8]=2.*3.1415/24./(365.*164.8)/3600.*x[8];
	d[8]=0;
	dp[8]=50000000.;
	col[8]=14;
	str1[8]="Neptune 8";
			/*Satellites ¥¯âã­ */
			/*’à¨â®­*/
	m[29]=214.e20;
	y[29]=y[8];
	x[29]=x[8]+354800000.;
	Vx[29]=0.0;
	Vy[29]=Vy[8]+2.*3.1415*354800000./(5.877*24.*3600.);
	d[29]=0;
	dp[29]=1350000.*2.;
	col[29]=14;
	str1[29]="Triton";
/* à ¬¥âàë ¤«ï «ãâ®­ */
	m[9]=1.3e22;
	y[9]=0.;
	x[9]=59.00e11;
	Vx[9]=0.0;
	Vy[9]=2.*3.1415/24./(365.*247.7)/3600.*x[9];
	d[9]=0;
	dp[9]=2800000.;
	col[9]=8;
	str1[9]="Pluto 9";
			/*Satellites «ãâ®­ */
			/*• à®­*/
	m[30]=18.e20;
	y[30]=y[9];
	x[30]=x[9]+19640000.;
	Vx[30]=0.0;
	Vy[30]=Vy[9]+2.*3.1415*19640000./(6.387*24.*3600.);
	d[30]=0;
	dp[30]=593000.*2.;
	col[30]=8;
	str1[30]="Charon";


/* à ¬¥âàë ¤«ï ‹ã­ë*/
	m[10]=mz/81.;
	x[10]=x[3]+384000000.;
	y[10]=y[3];

Vx[10]=Vx[3];/*+2.*3.1415*(y[10]-y[3])/27.333/24./3600.;*/
	Vy[10]=Vy[3]+2.*3.1415*(x[10]-x[3])/27.333/24./3600.;
	d[10]=0;
	dp[10]=3473000.;
	col[10]=14;
	str1[10]="Moon";
	uvel=2.;

	for(i=0;i<k;i++)
	{
		xs[i]=x[i];
		ys[i]=y[i];
	}
	maxrast=0.;
	for(i=0;i<k;i++)
	{
		maxrast=max(x[i],maxrast);
	}
	maxrast=maxrast*1.1;
	perx=0.0;pery=0.0;
h=500.;/* schag integrirowanija (sec.)*/
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


	for(t=0.;;t+=h,loop++)
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
			Vx[i]=Vx[i]+dux[i];
			Vy[i]=Vy[i]+duy[i];

		}
		if(loop>=20)
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
	outtextxy(maxx*0.9,6,"Time:");
	outtextxy(maxx*0.89,15,"(in day.)");


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
	 (y[i]-y[plan])/maxrast*maxy/2.+maxy/2./*+pery*/,col[i]);

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
					outtextxy(maxx*0.887,maxy*0.97,"(âëá.ª¬.)");

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

					if(plan==3)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.1,110,str1[10]);
					}

					if(plan==4)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.1,110,str1[11]);
						outtextxy(maxx/1.1,120,str1[12]);

					}

					if(plan==5)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.1,110,str1[13]);
						outtextxy(maxx/1.1,120,str1[14]);
						outtextxy(maxx/1.1,130,str1[15]);
						outtextxy(maxx/1.1,140,str1[16]);
					}

					if(plan==6)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.1,110,str1[17]);
						outtextxy(maxx/1.1,120,str1[18]);
						outtextxy(maxx/1.1,130,str1[19]);
						outtextxy(maxx/1.1,140,str1[20]);
						outtextxy(maxx/1.1,150,str1[21]);
						outtextxy(maxx/1.1,160,str1[22]);
						outtextxy(maxx/1.1,170,str1[23]);
					}
					if(plan==7)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.11,110,str1[24]);
						outtextxy(maxx/1.11,120,str1[25]);
						outtextxy(maxx/1.11,130,str1[26]);
						outtextxy(maxx/1.11,140,str1[27]);
						outtextxy(maxx/1.11,150,str1[28]);
					}
					if(plan==8)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.1,110,str1[29]);
					}

					if(plan==9)
					{
						outtextxy(maxx/1.12,70,"Satellites");
						outtextxy(maxx/1.12,80,"Planets");
						outtextxy(maxx/1.12,90,str1[plan]);
						outtextxy(maxx/1.1,110,str1[30]);
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