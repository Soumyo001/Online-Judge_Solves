#include<stdio.h>
int main(void)
{
    long long int n,i,fact=1;
    scanf("%lld",&n);
    if(n>=20)
    {
        printf("0000");
    }
    else
    {
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    fact%=10000;
    if(fact>=0&&fact<=9)
        printf("000%lld",fact);
    if(fact>=10&&fact<=99)
        printf("00%lld",fact);
    if(fact>=100&&fact<=999)
        printf("0%lld",fact);
    if(fact>=1000&&fact<=9999)
        printf("%lld",fact);
    }
}
