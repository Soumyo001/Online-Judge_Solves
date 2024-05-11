#include<stdio.h>
#include<math.h>
int main(void)
{
    int i,j,n,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        temp=i-1;
        for(j=1;j<=2*n-1;j++)
        {
            if(j>=n-(i-1)&&j<=n+(i-1))
            {
                if(temp<n)
                {
                    printf("%d",abs(temp));
                    temp--;
                }
               /* else
                {
                    printf("%d",abs(temp));
                    temp++;
                }*/
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}
