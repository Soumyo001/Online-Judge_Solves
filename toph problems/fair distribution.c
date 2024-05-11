#include<stdio.h>
int main(void)
{
    int x,y,extra;
    scanf("%d%d",&x,&y);
    if(y<=150)
    {if(y%x!=0)
    {
        for(int i=y;;i++)
        {
            if(i%x==0)
                {
                    extra=i;
                    break;
                }
        }
    }}
    extra-=y;
    printf("%d",extra);
}
