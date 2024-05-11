#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char msg[500],shifts[2]={'l','r'},choice;
    gets(msg);
    int n,i,len;
    printf("how many characters leftshift or rightshift ?\n");
    scanf("%d%s",&n, &choice);
    len=strlen(msg);
    switch(choice)
    {
        case 'r':
        {
             for(i=0;i<len;i++)
               {
                   if((msg[i]>='a'&&msg[i]<='z')||(msg[i]>='A'&&msg[i]<='Z'))
                      {
                          if(msg[i]+n>122||msg[i]+n>90)
                            {
                                if(isupper(msg[i]))
                                  {
                                    msg[i]=64+((msg[i]+n)-90);
                                  }
                                if(islower(msg[i]))
                                  {
                                    msg[i]=96+((msg[i]+n)-122);
                                  }
                           }
                           else
                                msg[i]+=n;
                      }
               }
          puts(msg);
          break;
        }
        case 'l':
            {
                 for(i=0;i<len;i++)
               {
                   if((msg[i]>='a'&&msg[i]<='z')||(msg[i]>='A'&&msg[i]<='Z'))
                      {
                          if(msg[i]-n<97||msg[i]-n<65)
                            {
                                if(isupper(msg[i]))
                                    msg[i]=91-(65-(msg[i]-n));
                                if(islower(msg[i]))
                                    msg[i]=123-(97-(msg[i]-n));
                           }
                           else
                            msg[i]-=n;
                      }
               }
             puts(msg);
             break;
            }
        default :
        printf("Wrong input");
    }
}
