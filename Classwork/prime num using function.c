#include<stdio.h>
int prime(int k)
{
    int count=0;
      for(int i=2;i<k;i++)
         {
             if(k%i==0)
                 count++;
                 break;
         }
         if(count)
            return 0;
            else return 1;
}
int main(void)
{
    int a;
    scanf("%d",&a);
    if(prime(a))
       printf("Prime");
       else 
        printf("Not prime");
        
}