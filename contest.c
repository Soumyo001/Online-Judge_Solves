#include<stdio.h>
int main(void)
{
    int a,i,x=1;
    printf("Enter ");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        if(i%2==0)
        {
          x+=(a-i)*(a-i);
        }
        else
        {
            x-=(a-i)*(a-i);
        }
    }
    printf("%d",x);
}

