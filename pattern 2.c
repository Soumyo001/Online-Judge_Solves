#include<stdio.h>
int main(void)
{
    int n,i,j,z=1;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++)
    {
        for(j=1;j<=2*n-1;j++)
        {
            if(i<=n){
            if(j>=n-(i-1)&&j<=n+(i-1))
                printf("*");
            else
                printf(" ");
            }
            else
            {
                if(j<2*n-z && j>z)
                   {
                     printf("*");
                   }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
        z++;
    }
}
