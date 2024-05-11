#include<stdio.h>
int rev();
int main(void)
{
    int n, r, re, num, remain, reverse=0;
    printf("Enter number = ");
    scanf("%d",&num);
    for(num;num!=0;num/=10)
    {
        remain=num%10;
        reverse=(reverse*10)+remain;
    }
    printf("Reverse number by for loop is %d\n",reverse);
    while(num!=0)
    {
        remain=num%10;
        num/=10;
        reverse=(reverse*10)+remain;
    }
    printf("Reverse number by while loop is %d\n",reverse);
}
