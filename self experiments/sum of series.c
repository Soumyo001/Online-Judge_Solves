#include<stdio.h>
#include<math.h>
int main(void)
{
   int i,j,n,x,sum=1,fact=1;
   float total=1;
   printf("Enter number ");
   scanf("%d",&x);
   printf("enter n th power ");
   scanf("%d",&n);
   for(i=2;i<=n;i+=2)
   {
    for(j=1;j<=i;j++)
     {
         sum*=x;
         fact*=j;
     }
    total+=(sum/(float)fact);
    fact=1;
    sum=1;
    }
   printf("%.3f\n",total);

}
