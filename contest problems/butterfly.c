#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,j,len1,len,count=0,n;
    scanf("%d",&n);
    fflush(stdin);
    char name[n];
    gets(name);
    len1=strlen(name);
    len=len1;
    len--;
    for(i=0,len;i<len1,len>=0;i++,len--)
    {
        if(name[i]==name[len])
                count++;
    }
    if(count==len1)
        printf("Yes");
    else
        printf("No");
}

