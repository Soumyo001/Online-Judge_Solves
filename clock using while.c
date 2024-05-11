#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main(void)
{
    int h,m,s,d=1000;
    printf("Enter the time in HH:MM:SS format ");
    scanf("%d%d%d",&h,&m,&s);
    start : ;
    while(h<24)
    {
        while(m<60)
        {
            while(s<60)
            {
                system("cls");
                printf("\n\n\n\t\t\t%d:%d:%d",h,m,s);
                if(h<12)
                    printf(" AM");
                else
                    printf(" PM");
                s++;
                Sleep(d);
            }
            s=0;
            m++;
        }
        m=0;
        h++;
    }
    h=0;
    goto start;
}
