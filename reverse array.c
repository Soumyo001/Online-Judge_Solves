#include<stdio.h>
int main(void)
{
    int a[10],i,j,n,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    j=n-1;
    for(i=0,j;i<n/2,j>=n/2;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
