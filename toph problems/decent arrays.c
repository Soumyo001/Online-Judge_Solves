#include<stdio.h>
#include<string.h>
int main(void)
{
    int a[100],i,n,count=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
            {
                count++;
            }
    }
    if(count==n)
        printf("Yes");
    else
        printf("No");
}
