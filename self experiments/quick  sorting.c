#include<stdlib.h>
#include<stdio.h>
int funcmpre(const void*x,const void*y){
   return *(int *)y-*(int *)x;}
int main(void)
{
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),funcmpre);
    for(int i=0;i<n;i++)
       printf("%d ",a[i]);
}