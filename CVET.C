#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
void main(void)

{
int Driver,Mode,i;
char str[10];
Driver=DETECT;
initgraph(&Driver,&Mode,"");
 for(i=0;i<45;i++)
 {
  setcolor(i);
  circle(10,i*10,3);
  gcvt(i,5,str);
  outtextxy(20,i*10,str);
  }
  }
