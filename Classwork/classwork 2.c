#include<stdio.h>
int main(void)
{
    int n1,n2,i,gcd;
    printf("Enter two numbers ");
    scanf("%d%d",&n1,&n2);
    for(i=1;i<=n1&&i<=n2;i++)
    {
        if(n1%i==0 && n2%i==0)
        {
            gcd=i;
        }
    }
    printf("GCD is %d\n",gcd);
    int n3,n4,x;
    printf("Enter two numbers ");
    scanf("%d%d",&n3,&n4);
    while(x!=0)
    {
        x=n4%n3;
        n4=n3;
        n3=x;
    }
    printf("The alternated way calculated GCD is %d\n",n4);
}
