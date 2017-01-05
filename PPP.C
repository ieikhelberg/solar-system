#include<conio.h>
main()
{
int i;
for(;;)
{
if(kbhit());
printf("%d",getch());
}
}
