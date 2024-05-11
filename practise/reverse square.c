#include<stdio.h>
int main(void)
{
    int n,remain,x,reverse=0,multi=1,y,multi1=1,temp,reverse1=0,remain1;
    printf("enter number ");
    scanf("%d",&n);
    for(x=1;x<=2;x++)
    {
      multi*=n;
    }
    temp=multi;
    for(n;n>0;n/=10)
    {
        remain=n%10;
        reverse=(reverse*10)+remain;
    }
    for(y=1;y<=2;y++)
    {
        multi1*=reverse;
    }
    for(temp;temp>0;temp/=10)
    {
        remain1=temp%10;
        reverse1=(reverse1*10)+remain1;
    }
    if(reverse1==multi1)
        printf("Applicable");
    else
        printf("Not applicable");


}
