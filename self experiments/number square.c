#include<stdio.h>
int main(void)
{
    int n,i,j,z=2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(n%2==0)
            {
            if(j>n/2)
            {
            if(i==1||i==n||j==1)
            {
                    printf("%d",j-z);
                    z+=2;
            }
            else if(j==n)
                        printf("%d",j-(n-1));
                else
                    printf(" ");
              }
              else
              {
                if(i==1||i==n||j==1||j==n)
               {
                    printf("%d",j);
                }
                else
                    printf(" ");
            }
        }
        else
        {
        if(j>(n+1)/2)
            {
            if(i==1||i==n||j==1)
            {
                    printf("%d",j-z);
                    z+=2;
            }
            else if(j==n)
                        printf("%d",j-(n-1));
                else
                    printf(" ");
              }
              else
              {
                if(i==1||i==n||j==1||j==n)
               {
                    printf("%d",j);
                }
                else
                    printf(" ");
            }
        }
    }
     printf("\n");
    z=2;
}
}
