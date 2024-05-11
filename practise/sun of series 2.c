#include<stdio.h>
int main(void)
{
    int i,j,sum=1,z=0,term,fact=1,n;
    float total=1;
    printf("Enter number ");
    scanf("%d",&n);
    printf("Enter term ");
    scanf("%d",&term);
    for(i=2;i<=term;i++)
    {
        if(i%2==0)
        {
            for(j=1;j<=i+z;j++)
            {
                sum*=n;
                fact*=j;
            }
            total-=(sum/(float)fact);
            sum=1;
            fact=1;
            z++;
        }
        else
        {
             for(j=1;j<=i+z;j++)
            {
                sum*=n;
                fact*=j;
            }
            total+=(sum/(float)fact);
            sum=1;
            fact=1;
            z++;
        }
    }
    printf("Sum of series = %.3f",total);
}
