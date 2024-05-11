#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main(void)
{
    int h=0,m=0,s=0,d=1000;
    printf("Enter the time format in HH:MM:SS = ");
    scanf("%d%d%d",&h,&m,&s);
    start : ;
    for(h;h<24;h++)
    {
        for(m;m<60;m++)
        {
            for(s;s<60;s++)
            {
                system("cls");
                printf("\n\n\n\t\t\t%d:%d:%d",h,m,s);
                if(h<12)
                    printf(" AM");
                else
                    printf(" PM");
                Sleep(d);
            }
            s=0;
        }
        m=0;
    }
    h=0;
    goto start;
}

