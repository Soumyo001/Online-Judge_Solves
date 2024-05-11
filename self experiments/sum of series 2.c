#include<stdio.h>
#include<math.h>
int main(void)
{
   int i,j,n,x,sum=1,y,fact=1,term,z=0,term1;
   float total=1;
   printf("Enter number ");
   scanf("%d",&x);
   /*printf("enter n th power ");
   scanf("%d",&n);*/
   printf("Enter n th term ");
   scanf("%d",&term1);
   /*y=(n/(float)2)+1;*/
   for(term=2;term<=term1;term++)
   {
       if(term%2==0)
       {
            for(j=1;j<=term+z;j++)
              {
                sum*=x;
                fact*=j;
              }
               total-=(sum/(float)fact);
              fact=1;
              sum=1;
               z++;
       }
       else
       {
              for(j=1;j<=term+z;j++)
                {
                  sum*=x;
                  fact*=j;
                }
                total+=(sum/(float)fact);
               fact=1;
               sum=1;
               z++;
       }
   }
   printf("%.4f",total);
}
