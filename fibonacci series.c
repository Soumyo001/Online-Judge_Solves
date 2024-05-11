#include<stdio.h>
int main(void)
{
    int f=0,s=1,n,fibo,count=0;
    printf("Enter range ");
    scanf("%d",&n);
    for(count;count<=n;count++)
    {
        if(count<=1)
            fibo=count;
        else
        {
            fibo=f+s;
            f=s;
            s=fibo;
        }
        printf("%d\t",fibo);
    }
}
