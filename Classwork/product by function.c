#include<stdio.h>
float pro(float x,int y)
    {
        return x*y;
    }
int main(void)
{
    int a;
    float c,b;
    scanf("%f%d",&b,&a);
    c=pro(b,a);
    printf("%f",c);
}
