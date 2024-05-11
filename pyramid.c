#include<stdio.h>
int main(void)
{
    int n,i,j;
    printf("Enter the rows of pyramid ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(2*n-1);j++)
        {
            if(j==n-(i-1)&&j==n+(i-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
   /* int num,rows,columns;
    printf("Enter N ");
    scanf("%d",&num);
    for(rows=1;rows<=num;rows++)
    {
        for(columns=1;columns<=rows;columns++)
        {
            printf("%c ",64+rows);
        }
            printf("\n");
    }*/

}
