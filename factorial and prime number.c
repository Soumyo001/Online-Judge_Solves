#include<stdio.h>
int main(void)
{
    long long int n,x,fact=1;
    printf("Enter factorial number: ");
    scanf("%lld",&n);
    for(x=1;x<=n;x++)
    {
        printf("%lld*%lld=%lld\n",fact,x,fact*x);
        fact*=x;
    }
    printf("Factorial is: %lld\n",fact);
    int num,i,count=0;
    printf("Enter numer ");
    scanf("%d",&num);
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
            count++;
            break;
        }
    }
    if(count==0)
        printf("Prime Number\n");
    else
        printf("Not a prime number\n");
}
