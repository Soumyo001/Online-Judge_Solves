#include<stdio.h>
int main(void)
{
    int f=0,s=1,i,count=0,n=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i<=1)
           {
               printf("%d ",count);
               count++;
           }
        else{
            count=f+s;
            f=s;
            s=count;
            printf("%d ",count);
        }
    }
}