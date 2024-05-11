#include<stdio.h>
int main(void)
{
    int x,term,i,j,fact=1,po=1;
    scanf("%d",&x);
    scanf("%d",&term);
    float temp=x;
    for(i=2;i<=term;i++)
    {
        for(j=1;j<=i;j++)
        {
            fact*=j;
            po*=x;
        }
        temp+=(po/(float)fact);
        po=1;
        fact=1;
    }
    printf("%f",temp);
}
