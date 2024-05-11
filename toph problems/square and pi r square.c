#include<stdio.h>
#include<math.h>
double pi=3.141592653589793;
int main(void)
{
    int r,i,sum=1;
    double a;
    scanf("%d",&r);
    for(i=1;i<=2;i++)
    {
        sum*=r;
    }
    printf("%d",sum);
    sum=1;
    scanf("%d",&r);
    for(i=1;i<=2;i++)
    {
        sum*=r;
    }
    a=pi*sum;
    printf("%.10lf",a);
}
