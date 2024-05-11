#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main(void)
{
    int a, b, d=10;
    printf("Enter values ");
    scanf("%d%d",&a,&b);
    start : ;
    for(a;a<10;a++)
    {
        for(b;b<20;b++)
        {

            system("cls");
            printf("\n\n\n\t\t\t%d:%d",a,b);
            if(a<5)
                printf(" Fuck");
            else
                printf(" Suck");
            Sleep(d);
        }
        b=0;
    }
    a=0;
    goto start;
}
