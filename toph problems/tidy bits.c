#include<stdio.h>
int main(void)
{
   int n,i=0;
   int bin[100];
   scanf("%d",&n);
   while(n)
   {
       bin[i]=n%2;
       n/=2;
       i++;
   }
   i--;
   while(i>=0)
   {
       printf("%d",bin[i]);
       i--;
   }
}
