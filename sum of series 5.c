#include<stdio.h>
#include<math.h>
int main(void)
{
    int i,j,term,sum=0,fact=1,po=1,x;
    float total=1;
    scanf("%d",&term);
    for(i=1;i<=term;i++)
    {
        for(j=1;j<=i;j++)
        {
            sum+=j;
        }
    }
    printf("%d\n",sum);
    scanf("%d",&term);
    for(i=2;i<=term;i++)
    {
        for(j=1;j<=i;j++)
        {
            fact*=j;
        }
        total+=pow(i,2)/(float)fact;
        fact=1;
    }
     printf("%f\n",total);
}
