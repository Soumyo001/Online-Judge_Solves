#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(void){
    char a[100];
    int i=1,t,l,*p;
    gets(a);
    if(strlen(a)%2==0)
         l=strlen(a)+(strlen(a)/2)+5;
    else
       l=strlen(a)+((strlen(a)+1)/2)+5;
       t=l;
       p=(int *)malloc(l*sizeof(int));
       l-=1;
       while(l>=0){
                p[l]=a[strlen(a)-i];
                p[l-1]='_';
                i++;
                if(!isalnum(a[strlen(a)-i]))
                l--;
                else if(!isalnum(p[l]))
                l--;
                else
                l-=2;
            }
    for(int x=0;x<t;x++) {printf("%c",p[x]);}
}