#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,len1,len,count=0;
    char name[100];
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
