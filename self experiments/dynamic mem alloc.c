#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t",p[i]);
    }
    int *k=(int *)realloc(p,2*n*sizeof(int));
    for(int i=n;i<2*n;i++)
        scanf("%d",&k[i]);
    for(int i=0;i<2*n;i++)
        printf("%d\n",k[i]);
    free(p);
    printf("\n");
     for(int i=0;i<2*n;i++)
        {
            printf("%d\t",k[i]);
        }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",p[i]);
    }
}
