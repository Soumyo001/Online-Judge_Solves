#include <stdio.h>
#include<string.h>
int main(void)
{
    char r[25][25];
    int col,row,i,j,count=0;
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
        scanf("%s",&r[i][j]);
    }
    }
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
        if(r[i][j]=='.')
        {
        if(r[i][j+1]!='*'&&r[i][j-1]!='*'&&r[i+1][j]!='*'&&r[i-1][j]!='*')
        count++;
        }
    }
    }
    printf("%d",count);
}
