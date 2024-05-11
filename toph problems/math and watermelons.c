#include<stdio.h>
int main(void)
{
    int m,k,s;
    scanf("%d%d",&m,&k);
    s=m/k;
    k*=s;
    m-=k;
    printf("%d",m);
}
