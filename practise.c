#include<stdio.h>
int main (void)
{
    int n,temp,sum=0,remain;
    printf("Enter number to confirm whether armstrong or not ");
    scanf("%d",&n);
    temp=n;
    for(n;n>0;n/=10)
    {
        remain=n%10;
        sum+=remain*remain*remain;
    }
    if(sum==temp)
        printf("Armstrong\n");
    else
        printf("Not armstrong\n");
    int num,count=0,i;
    printf("Enter the number to confirm prime number or not ");
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
       printf("Prime number\n");
    else
        printf("Not a prime number\n");
    long long int number,x,sumation=1;
    printf("Enter Number for factorial ");
    scanf("%lld",&number);
    for(x=1;x<=number;x++)
    {
        printf("%lld*%lld=%lld\n",sumation,x,sumation*x);
        sumation*=x;
    }
    printf("Factorial is %lld\n",sumation);
}
