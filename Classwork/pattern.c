#include<stdio.h>
int main(void)
{
    int i,j;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            if(i==1||i==5||j==1||j==5)
                printf("%d",j);

            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
    int k,l;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
                printf("%d",j);

        }
        printf("\n");
    }
}
