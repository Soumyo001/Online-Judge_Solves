#include<stdio.h>
#include<math.h>
int main(void)
{
   int i,j,n,sum=1,fact=1,x;
   float temp;
   printf("Enter number ");
   scanf("%d",&x);
   printf("enter n th power ");
   scanf("%d",&n);
   temp=x;
   for(i=2;i<=n;i++)
   {
    for(j=1;j<=i;j++)
     {
         sum*=x;
         fact*=j;
     }
    temp+=(sum/(float)fact);
    fact=1;
    sum=1;
    }
   printf("%.3f\n",temp);

}
