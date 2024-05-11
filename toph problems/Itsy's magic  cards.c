#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    char c[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%c",&c[i][j]);
        }
    }
}
