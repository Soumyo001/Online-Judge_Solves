#include<stdio.h>
int main(void)
{
    int n,j,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*n-1;j++)
        {
            if(j>=n-(i-1)&&j<=n+(i-1))
            {
                if(j%2==0)
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                }
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}
