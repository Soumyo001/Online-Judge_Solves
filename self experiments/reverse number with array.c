#include<stdio.h>
int main(void)
{
    int a[100],i,n,len;
    printf("Enter digit ");
    scanf("%d",&n);
    printf("Enter the number ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    n--;
    printf("Reverse is ");
    for(n;n>=0;n--)
    {
        printf("%d",a[n]);
    }
}
