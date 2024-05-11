#include<stdio.h>
int main(void)
{
    int t,i,max=0;
    scanf("%d",&t);
    int n[1000];
    for(i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
    }
    for(i=0;i<t;i++)
    {
        if(n[i]>max)
            max=n[i];
    }
    printf("%d",max);
}
