#include<stdio.h>
int main(void)
{
    int i,n,a,b,x[99],sum=0;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=a;i<=b;i++)
    {
        sum+=x[i];
    }
    printf("%d",sum);
}
