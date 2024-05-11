#include<stdio.h>
int main(void)
{
    int n,s,sum=0,i;
    float avg;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s);
        sum+=s;
        avg=(float)sum/i;
        printf("%.4f\n",avg);
    }
}
