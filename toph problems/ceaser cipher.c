#include <stdio.h>
#include <string.h>
#include<ctype.h>
int main(void)
{
    int i=1,len,n;
    char msg[500];
    scanf("%d",&n);
    fflush(stdin);
    gets(msg);
    len=strlen(msg);
    for(i=0;i<len;i++)
    {
        if((msg[i]>='A'&&msg[i]<='Z')||(msg[i]>='a'&&msg[i]<='z'))
        {
            if(msg[i]-n<97||msg[i]-n<65)
            {
                if(islower(msg[i]))
                msg[i]=123-(97-(msg[i]-n));
                if(isupper(msg[len]))
                msg[i]=91-(65-(msg[i]-n));
            }
            else
                msg[i]-=n;
        }
    }
    puts(msg);

}
