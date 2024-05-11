#include<stdio.h>
#include<string.h>
int main(void)
{
    int r,c;
    char a[100][100];
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%s", &a[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]=='.')
            {
                int count=0;
                if(a[i][j-1]=='*')
                    count++;
                if(a[i][j+1]=='*')
                    count++;
                if(a[i-1][j]=='*')
                    count++;
                if(a[i-1][j+1]=='*')
                    count++;
                if(a[i-1][j-1]=='*')
                    count++;
                if(a[i+1][j]=='*')
                    count++;
                if(a[i+1][j+1]=='*')
                    count++;
                if(a[i+1][j-1]=='*')
                    count++;
                if(count==0)
                   printf(".");
                else
                    printf("%d",count);
            }
            else
                printf("*");

        }
        printf("\n");
    }
}
