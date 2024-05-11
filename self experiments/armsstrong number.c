#include<stdio.h>
int main(void)
{
    int num, temp, sum=0, remain;
    printf("enter number ");
    scanf("%d",&num);
    temp=num;
    for(temp;temp>0;temp/=10)
    {
        remain=temp%10;
        sum+=remain*remain*remain;
    }
    if(sum==num)
        printf("Armstrong number\n");
    else
        printf("not a armstrong number\n");

}
