#include<stdio.h>
#include<string.h>
int main(void)
{
    char n[1010000],ch;
    int i,max=0,l,ans=0,j,count,temp=0;
    scanf("%s", n);
    l=strlen(n);
    for(i=0;i<l;i++)
    {
    count=0;
    for(j=0;j<l;j++)
    {
        if(n[i]==n[j])
        {
            count++;
        }
    }
    if(count>max)
    {
        ch=n[i];
        max=count;
    }
  }
    printf("%c",ch);
}
    /*{
        if(n[i]>=max)
        {
            if(n[i]==max)
                 ans++;
            if(max<n[i])
               {ans=0;
               ans++;
               max=n[i];
               }
        }
    }
    printf("%d",ans);
}*/
