#include <stdio.h>
int main(void)
{
    int n1,n2,i,r1,r2,count=0;
    scanf("%d%d",&n1,&n2);
    for(n1,n2;n1>0,n2>0;n1/=10,n2/=10)
    {
        r1=n1%10;
        r2=n2%10;
        if(r1+r2>9)
        {
            count=1;
        }
    }
    if(count)
        printf("Yes");
    else
        printf("No");
}
