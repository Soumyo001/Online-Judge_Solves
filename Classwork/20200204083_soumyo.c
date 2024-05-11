#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,temp,i,j,r,count=0;
    for(j=10;j<=10000;j++)
    {
    int sum=0,sq;
    n=j;
    sq=pow(n,2);
    temp=sq;//144
    sq=1;
    for(n;n!=0;n/=10)
    {
        r=n%10;
        sum=(sum*10)+r;
    }
    sq=pow(sum,2);
    sum=0;
    for(sq;sq!=0;sq/=10)
    {
        r=sq%10;
        sum=(sum*10)+r;
    }
    n=sqrt(sum);
    if(sum==temp)
    {
        printf("%d\t",j);
        count++;
    }
    }
    printf("\n%d",count);

}
