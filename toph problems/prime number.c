#include <stdio.h>
#include <math.h>

/*int prime(int x)
{
    int i, root;
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    root=sqrt(x);
    for(i=3; i<=root; i=i+2)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int X;
        scanf("%d", &X);
        if(1==prime(X))
            printf("Yes");
        else if(0==prime(X))
            printf("No");
    return 0;
}*/
int main(void)
{
    int n,i,count=0;
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            count++;
    }
    if(count==0)
        printf("Yes");
    else
        printf("No");
}
