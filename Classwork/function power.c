#include<stdio.h>
int power(int x,int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x,y-1);
}
int main(void)
{
    int a,b,p;
    scanf("%d%d",&a,&b);
    p=power(a,b);
    printf("%d",p);
}
