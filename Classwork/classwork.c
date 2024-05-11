#include<stdio.h>
int main(void)
{
    int N,x=1900,count=0;
    printf("Enter current year ");
    scanf("%d",&N);
    for(x;N>x;x++)
    {
        if(x%4==0&&x%100!=0||x%400==0)
        {
            printf("Leap Year %d\n",x);
            count++;
        }
    }
    printf("Total count %d\n",count);
}
