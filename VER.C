#include<math.h>
#include<conio.h>

double  fact(float f);
void main(void)
{
double P,n,k,p;
n=1200.;
k=0.;
p=0.002;
   clrscr();
   P=fact(4.);
   printf("%f",n/60.);
   P=1-pow(1-p,n);
   printf("\n%f",P);


}
double fact(float f)
{
double i,x;
x=1.;

for(i=1 ;i<f+1.;i++)
x=x*i;
return x;

}