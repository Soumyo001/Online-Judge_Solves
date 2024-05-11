#include<stdio.h>
int main(void)
{
    int n1,n2,gcd,lcd,i;
    printf("Enter two numbers ");
    scanf("%d%d",&n1,&n2);
    for(i=1;i<=n1&&i<=n2;i++)
    {
        if(n1%i==0&&n2%i==0)
        {
            gcd=i;
        }
    }
    printf("GCD is %d\n",gcd);
    lcd=(n1*n2)/gcd;
    printf("LCD is %d\n",lcd);
    int n3,n4,num3,num4,remain,lcd1;
    printf("Enter two numbers ");
    scanf("%d%d",&n3,&n4);
    num3=n3;
    num4=n4;
    while(n4!=0)
    {
        remain=n3%n4;
        n3=n4;
        n4=remain;
    }
    printf("Alter way calculated GCD is %d\n",n3);
    lcd1=(num3*num4)/n3;
    printf("Alter way calculated LCD is %d\n",lcd1);

}
