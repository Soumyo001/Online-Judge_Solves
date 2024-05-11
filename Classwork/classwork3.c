#include<stdio.h>
int main(void)
{
    int n,i,sum=0;//this is the program of perfect number
    printf("Enter number ");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(sum==n)
        printf("Perfect");
    else
        printf("Not perfect");
}
