#include<stdio.h>
int main(void)
{
    int n,i,j=1,z=2,sum=0,term;
    printf("Enter n th term ");
    scanf("%d",&term);
    for(i=1;i<=term;i++)
    {
        sum+=(j-z);
        j+=2;
        z+=2;
    }
    printf("Sum is %d",sum);
}
