#include<stdio.h>
int main(void)
{
    long long int num1,num2,i,x,z,n=1,r=1,c=1,ncr;
    printf("Enter numbers for performing ncr: ");
    scanf("%lld%lld",&num1,&num2);
    if(num1>num2)
    {
    for(x=1;x<=num1;x++)
    {
        printf("%lld*%lld=%lld\n",n,x,n*x);
        n*=x;
    }
    printf("Factorial is: %lld\n",n);
         for(i=1;i<=num2;i++)
    {
        printf("%lld*%lld=%lld\n",r,i,r*i);
        r*=i;
    }
    printf("Factorial is: %lld\n",r);
    for(z=1;z<=(num1-num2);z++)
    {
       printf("%lld*%lld=%lld\n",c,z,c*z);
       c*=z;
    }
    ncr=n/(r*c);
    printf("ncr is %lld\n",ncr);
    }
    else
        printf("Learn ncr then input the values\n");

}
