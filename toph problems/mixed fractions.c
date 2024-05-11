#include<stdio.h>
int main(void)
{
    int n,d,a,k;
    scanf("%d%d",&n,&d);
    a=n/d;
    k=n%d;
    printf("%d %d %d",a,k,d);
}
