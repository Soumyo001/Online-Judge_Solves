#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char p[17];
    int i,j,len;
    gets(p);
    len=strlen(p);
    for(i=0;i<len;i++)
    {
        if(i==0)
            p[i]=toupper(p[i]);
        if(p[i]=='s')
            p[i]='$';
        if(p[i]=='i')
            p[i]='!';
        if(p[i]=='o')
        {
            p[i]=')';
            len++;
            for(j=len-2;j>=i;j--)
            {
                p[j+1]=p[j];
            }
            p[i]='(';
        }
    }
    p[len]='.';
    p[len+1]='\0';
    printf("%s",p);
}
