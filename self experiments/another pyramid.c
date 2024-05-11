#include<stdio.h>
int main(void)
{
    int n,i,j,z=0,temp;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++)
    {
        if(i<=n)
        {
            for(j=1;j<=i;j++)
            {
                printf("\t%d",i*j);
            }
            printf("\n");
        }
        else
        {
            temp=i;
            temp-=(2+z);
            for(j=1;j<=temp;j++)
            {
                printf("\t%d",temp*j);
            }
            printf("\n");
            z+=2;
        }
    }
}
