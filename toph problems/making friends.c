#include<stdio.h>
int main(void)
{
    int i,n,count=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
            count++;
    }
    printf("%d",count);
}
