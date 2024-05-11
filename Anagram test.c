#include<stdio.h>
#include<string.h>
int main(void)
{
    char x[100],y[100];
    int len1,len2,len,i,j,found=0,notfound=0,temp;
    printf("Enter first word ");
    gets(x);
    printf("Enter Sceond ");
    gets(y);
    len1=strlen(x);
    len2=strlen(y);
    if(len1==len2)
    {
        len=len1;
        for(i=0;i<len;i++)
        {
            for(j=0;j<len;j++)
            {
                if(x[i]==y[j])
                {
                    found+=1;
                    break;
                }
            }
        }
        if(found==len)
            printf("Anagram");
        else
            printf("Not Anagram");
    }
    else
        printf("Lengths are not same");
}
