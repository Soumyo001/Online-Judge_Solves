#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char s[105];
    int t,i,j,over,ball,len,count;
    scanf("%d",&t);
    while(t--)
    {
        fflush(stdin);
        scanf("%s", s);
        len=strlen(s);
        count=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='D'||s[i]=='W'||s[i]=='N')
               {
                   count++;
               }
        }
        len-=count;
        over=len/6;
        ball=len%6;
        if(over>=1&&ball>=1)
        {
            if(over==1&&ball>=1)
                printf("%d OVER %d %s\n",over,ball,(ball>1)?"BALLS":"BALL");
            else if(over>=1&&ball==1)
                printf("%d %s %d BALL\n",over,(over>1)?"OVERS":"OVER",ball);
        }
        else if(over==0)
        {
            if(ball==1)
                printf("%d BALL\n",ball);
            else
                printf("%d BALLS\n",ball);
        }
        else if(ball==0)
        {
            if(over==1)
                printf("%d OVER\n",over);
            else
                printf("%d OVERS\n",over);
        }
    }
}

