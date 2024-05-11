#include<stdio.h>
int main(void)
{
    long long int n,i,j,k,l;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        {
           for(j=1;j<=(2*n-1);j++)
               {
                 if(j>=n-(i-1)&&j<=n+(i-1))
                 {
                      if(j%2==0)
                          printf("*");
                      else
                        printf(" ");
                 }
                 else
                    printf(" ");
                }
        printf("\n");
        }
        else
        {
             for(j=1;j<=(2*n-1);j++)
               {
                 if(j>=n-(i-1)&&j<=n+(i-1))
                 {
                      if(j%2==0)
                        printf(" ");
                      else
                        printf("*");

                 }
                 else
                    printf(" ");
              }
        printf("\n");
        }
    }
}
